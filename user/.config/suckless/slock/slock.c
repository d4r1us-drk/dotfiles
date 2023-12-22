/* See LICENSE file for license details. */
#include <X11/Xmd.h>
#define _XOPEN_SOURCE 500
#if HAVE_SHADOW_H
#include <shadow.h>
#endif

#include <ctype.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <X11/extensions/Xrandr.h>
#include <X11/extensions/dpms.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <Imlib2.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>

#include "arg.h"
#include "util.h"

char *argv0;
static int pam_conv(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr);
struct pam_conv pamc = {pam_conv, NULL};
char passwd[256];

enum {
	INIT,
	INPUT,
	FAILED,
	CAPS,
	PAM,
	NUMCOLS
};

struct lock {
	int screen;
	Window root, win;
	Pixmap pmap;
	Pixmap bgmap;
	unsigned long colors[NUMCOLS];
};

struct xrandr {
	int active;
	int evbase;
	int errbase;
};

#include "config.h"

Imlib_Image image;

static void
die(const char *errstr, ...)
{
	va_list ap;

	va_start(ap, errstr);
	vfprintf(stderr, errstr, ap);
	va_end(ap);
	exit(1);
}

static int
pam_conv(int num_msg, const struct pam_message **msg,
		struct pam_response **resp, void *appdata_ptr)
{
	int retval = PAM_CONV_ERR;
	for(int i=0; i<num_msg; i++) {
		if (msg[i]->msg_style == PAM_PROMPT_ECHO_OFF &&
				strncmp(msg[i]->msg, "Password: ", 10) == 0) {
			struct pam_response *resp_msg = malloc(sizeof(struct pam_response));
			if (!resp_msg)
				die("malloc failed\n");
			char *password = malloc(strlen(passwd) + 1);
			if (!password)
				die("malloc failed\n");
			memset(password, 0, strlen(passwd) + 1);
			strcpy(password, passwd);
			resp_msg->resp_retcode = 0;
			resp_msg->resp = password;
			resp[i] = resp_msg;
			retval = PAM_SUCCESS;
		}
	}
	return retval;
}

#ifdef __linux__
#include <fcntl.h>
#include <linux/oom.h>

static void
dontkillme(void)
{
	FILE *f;
	const char oomfile[] = "/proc/self/oom_score_adj";

	if (!(f = fopen(oomfile, "w"))) {
		if (errno == ENOENT)
			return;
		die("slock: fopen %s: %s\n", oomfile, strerror(errno));
	}
	fprintf(f, "%d", OOM_SCORE_ADJ_MIN);
	if (fclose(f)) {
		if (errno == EACCES)
			die("slock: unable to disable OOM killer. "
			    "Make sure to suid or sgid slock.\n");
		else
			die("slock: fclose %s: %s\n", oomfile, strerror(errno));
	}
}
#endif

static const char *
gethash(void)
{
	const char *hash;
	struct passwd *pw;

	/* Check if the current user has a password entry */
	errno = 0;
	if (!(pw = getpwuid(getuid()))) {
		if (errno)
			die("slock: getpwuid: %s\n", strerror(errno));
		else
			die("slock: cannot retrieve password entry\n");
	}
	hash = pw->pw_passwd;

#if HAVE_SHADOW_H
	if (!strcmp(hash, "x")) {
		struct spwd *sp;
		if (!(sp = getspnam(pw->pw_name)))
			die("slock: getspnam: cannot retrieve shadow entry. "
			    "Make sure to suid or sgid slock.\n");
		hash = sp->sp_pwdp;
	}
#else
	if (!strcmp(hash, "*")) {
#ifdef __OpenBSD__
		if (!(pw = getpwuid_shadow(getuid())))
			die("slock: getpwnam_shadow: cannot retrieve shadow entry. "
			    "Make sure to suid or sgid slock.\n");
		hash = pw->pw_passwd;
#else
		die("slock: getpwuid: cannot retrieve shadow entry. "
		    "Make sure to suid or sgid slock.\n");
#endif /* __OpenBSD__ */
	}
#endif /* HAVE_SHADOW_H */

	/* pam, store user name */
	hash = pw->pw_name;
	return hash;
}

static void
readpw(Display *dpy, struct xrandr *rr, struct lock **locks, int nscreens,
       const char *hash)
{
	XRRScreenChangeNotifyEvent *rre;
	char buf[32];
	int caps, num, screen, running, failure, oldc, retval;
	unsigned int len, color, indicators;
	KeySym ksym;
	XEvent ev;
	pam_handle_t *pamh;

	len = 0;
    caps = 0;
	running = 1;
	failure = 0;
	oldc = INIT;

	if (!XkbGetIndicatorState(dpy, XkbUseCoreKbd, &indicators))
		caps = indicators & 1;

	while (running && !XNextEvent(dpy, &ev)) {
		if (ev.type == KeyPress) {
			explicit_bzero(&buf, sizeof(buf));
			num = XLookupString(&ev.xkey, buf, sizeof(buf), &ksym, 0);
			if (IsKeypadKey(ksym)) {
				if (ksym == XK_KP_Enter)
					ksym = XK_Return;
				else if (ksym >= XK_KP_0 && ksym <= XK_KP_9)
					ksym = (ksym - XK_KP_0) + XK_0;
			}
			if (IsFunctionKey(ksym) ||
			    IsKeypadKey(ksym) ||
			    IsMiscFunctionKey(ksym) ||
			    IsPFKey(ksym) ||
			    IsPrivateKeypadKey(ksym))
				continue;
			switch (ksym) {
			case XK_Return:
				passwd[len] = '\0';
				errno = 0;
				retval = pam_start(pam_service, hash, &pamc, &pamh);
				color = PAM;
				for (screen = 0; screen < nscreens; screen++) {
					XSetWindowBackground(dpy, locks[screen]->win, locks[screen]->colors[color]);
					XClearWindow(dpy, locks[screen]->win);
					XRaiseWindow(dpy, locks[screen]->win);
				}
				XSync(dpy, False);

				if (retval == PAM_SUCCESS)
					retval = pam_authenticate(pamh, 0);
				if (retval == PAM_SUCCESS)
					retval = pam_acct_mgmt(pamh, 0);

				running = 1;
				if (retval == PAM_SUCCESS)
					running = 0;
				else
					fprintf(stderr, "slock: %s\n", pam_strerror(pamh, retval));
				pam_end(pamh, retval);
				if (running) {
					XBell(dpy, 100);
					failure = 1;
				}
				explicit_bzero(&passwd, sizeof(passwd));
				len = 0;
				break;
			case XK_Escape:
				explicit_bzero(&passwd, sizeof(passwd));
				len = 0;
				break;
			case XK_BackSpace:
				if (len)
					passwd[--len] = '\0';
				break;
			case XK_Caps_Lock:
				caps = !caps;
				break;
			default:
				if (num && !iscntrl((int)buf[0]) &&
				    (len + num < sizeof(passwd))) {
					memcpy(passwd + len, buf, num);
					len += num;
				}
				break;
			}
			color = len ? (caps ? CAPS : INPUT) : (failure || failonclear ? FAILED : INIT);
			if (running && oldc != color) {
				for (screen = 0; screen < nscreens; screen++) {
                                        if (locks[screen]->bgmap)
                                                XSetWindowBackgroundPixmap(dpy, locks[screen]->win, locks[screen]->bgmap);
                                        else
                                                XSetWindowBackground(dpy, locks[screen]->win, locks[screen]->colors[0]);
					XClearWindow(dpy, locks[screen]->win);
				}
				oldc = color;
			}
		} else if (rr->active && ev.type == rr->evbase + RRScreenChangeNotify) {
			rre = (XRRScreenChangeNotifyEvent*)&ev;
			for (screen = 0; screen < nscreens; screen++) {
				if (locks[screen]->win == rre->window) {
					if (rre->rotation == RR_Rotate_90 ||
					    rre->rotation == RR_Rotate_270)
						XResizeWindow(dpy, locks[screen]->win,
						              rre->height, rre->width);
					else
						XResizeWindow(dpy, locks[screen]->win,
						              rre->width, rre->height);
					XClearWindow(dpy, locks[screen]->win);
					break;
				}
			}
		} else {
			for (screen = 0; screen < nscreens; screen++)
				XRaiseWindow(dpy, locks[screen]->win);
		}
	}
}

static struct lock *
lockscreen(Display *dpy, struct xrandr *rr, int screen)
{
	char curs[] = {0, 0, 0, 0, 0, 0, 0, 0};
	int i, ptgrab, kbgrab;
	struct lock *lock;
	XColor color, dummy;
	XSetWindowAttributes wa;
	Cursor invisible;

	if (dpy == NULL || screen < 0 || !(lock = malloc(sizeof(struct lock))))
		return NULL;

	lock->screen = screen;
	lock->root = RootWindow(dpy, lock->screen);

        if(image)
        {
            lock->bgmap = XCreatePixmap(dpy, lock->root, DisplayWidth(dpy, lock->screen), DisplayHeight(dpy, lock->screen), DefaultDepth(dpy, lock->screen));
            imlib_context_set_display(dpy);
            imlib_context_set_visual(DefaultVisual(dpy, lock->screen));
            imlib_context_set_colormap(DefaultColormap(dpy, lock->screen));
            imlib_context_set_drawable(lock->bgmap);
            imlib_render_image_on_drawable(0, 0);
            imlib_free_image();
        }

	for (i = 0; i < NUMCOLS; i++) {
		XAllocNamedColor(dpy, DefaultColormap(dpy, lock->screen),
		                 colorname[i], &color, &dummy);
		lock->colors[i] = color.pixel;
	}

	/* init */
	wa.override_redirect = 1;
	wa.background_pixel = lock->colors[INIT];
	lock->win = XCreateWindow(dpy, lock->root, 0, 0,
	                          DisplayWidth(dpy, lock->screen),
	                          DisplayHeight(dpy, lock->screen),
	                          0, DefaultDepth(dpy, lock->screen),
	                          CopyFromParent,
	                          DefaultVisual(dpy, lock->screen),
	                          CWOverrideRedirect | CWBackPixel, &wa);
        if(lock->bgmap)
          XSetWindowBackgroundPixmap(dpy, lock->win, lock->bgmap);
	lock->pmap = XCreateBitmapFromData(dpy, lock->win, curs, 8, 8);
	invisible = XCreatePixmapCursor(dpy, lock->pmap, lock->pmap,
	                                &color, &color, 0, 0);
	XDefineCursor(dpy, lock->win, invisible);

	/* Try to grab mouse pointer *and* keyboard for 600ms, else fail the lock */
	for (i = 0, ptgrab = kbgrab = -1; i < 6; i++) {
		if (ptgrab != GrabSuccess) {
			ptgrab = XGrabPointer(dpy, lock->root, False,
			                      ButtonPressMask | ButtonReleaseMask |
			                      PointerMotionMask, GrabModeAsync,
			                      GrabModeAsync, None, invisible, CurrentTime);
		}
		if (kbgrab != GrabSuccess) {
			kbgrab = XGrabKeyboard(dpy, lock->root, True,
			                       GrabModeAsync, GrabModeAsync, CurrentTime);
		}

		/* input is grabbed: we can lock the screen */
		if (ptgrab == GrabSuccess && kbgrab == GrabSuccess) {
			XMapRaised(dpy, lock->win);
			if (rr->active)
				XRRSelectInput(dpy, lock->win, RRScreenChangeNotifyMask);

			XSelectInput(dpy, lock->root, SubstructureNotifyMask);
			return lock;
		}

		/* retry on AlreadyGrabbed but fail on other errors */
		if ((ptgrab != AlreadyGrabbed && ptgrab != GrabSuccess) ||
		    (kbgrab != AlreadyGrabbed && kbgrab != GrabSuccess))
			break;

		usleep(100000);
	}

	/* we couldn't grab all input: fail out */
	if (ptgrab != GrabSuccess)
		fprintf(stderr, "slock: unable to grab mouse pointer for screen %d\n",
		        screen);
	if (kbgrab != GrabSuccess)
		fprintf(stderr, "slock: unable to grab keyboard for screen %d\n",
		        screen);
	return NULL;
}

static void
usage(void)
{
	die("usage: slock [-v] [cmd [arg ...]]\n");
}

int
main(int argc, char **argv) {
	struct xrandr rr;
	struct lock **locks;
	struct passwd *pwd;
	struct group *grp;
	uid_t duid;
	gid_t dgid;
	const char *hash;
    const char *custom_background = NULL;
	Display *dpy;
	int s, nlocks, nscreens;
	CARD16 standby, suspend, off;
	BOOL dpms_state;

	ARGBEGIN {
	case 'v':
		puts("slock-"VERSION);
		return 0;
    case 'b':
        if (argc > 1) {
            custom_background = argv[1];
            argc--;
            argv++;
        } else {
            die("slock: -b requires an argument\n");
        }
        break;
	default:
		usage();
	} ARGEND

	/* validate drop-user and -group */
	errno = 0;
	if (!(pwd = getpwnam(getenv("USER"))))
		die("slock: getpwnam %s: %s\n", getenv("USER"),
		    errno ? strerror(errno) : "user entry not found");
	duid = pwd->pw_uid;
	errno = 0;
	if (!(grp = getgrnam(getenv("USER"))))
		die("slock: getgrnam %s: %s\n", getenv("USER"),
		    errno ? strerror(errno) : "group entry not found");
	dgid = grp->gr_gid;

#ifdef __linux__
	dontkillme();
#endif

	/* the contents of hash are used to transport the current user name */
	hash = gethash();
	errno = 0;

	if (!(dpy = XOpenDisplay(NULL)))
		die("slock: cannot open display\n");

	/* drop privileges */
	if (setgroups(0, NULL) < 0)
		die("slock: setgroups: %s\n", strerror(errno));
	if (setgid(dgid) < 0)
		die("slock: setgid: %s\n", strerror(errno));
	if (setuid(duid) < 0)
		die("slock: setuid: %s\n", strerror(errno));

	/* Load picture */
    Imlib_Image buffer = imlib_load_image(custom_background ? custom_background : background_image);
    imlib_context_set_image(buffer);
    int background_image_width = imlib_image_get_width();
    int background_image_height = imlib_image_get_height();

        /* Create an image to be rendered */
	Screen *scr = ScreenOfDisplay(dpy, DefaultScreen(dpy));
	image = imlib_create_image(scr->width, scr->height);
    imlib_context_set_image(image);

    /* Fill the image for every X monitor */
    XRRMonitorInfo	*monitors;
    int number_of_monitors;
    monitors = XRRGetMonitors(dpy, RootWindow(dpy, XScreenNumberOfScreen(scr)), True, &number_of_monitors);

    int i;
    for (i = 0; i < number_of_monitors; i++) {
        imlib_blend_image_onto_image(buffer, 0, 0, 0, background_image_width, background_image_height, monitors[i].x, monitors[i].y, monitors[i].width, monitors[i].height);
    }

    /* Clean up */
    imlib_context_set_image(buffer);
    imlib_free_image();
    imlib_context_set_image(image);

	/* check for Xrandr support */
	rr.active = XRRQueryExtension(dpy, &rr.evbase, &rr.errbase);

	/* get number of screens in display "dpy" and blank them */
	nscreens = ScreenCount(dpy);
	if (!(locks = calloc(nscreens, sizeof(struct lock *))))
		die("slock: out of memory\n");
	for (nlocks = 0, s = 0; s < nscreens; s++) {
		if ((locks[s] = lockscreen(dpy, &rr, s)) != NULL)
			nlocks++;
		else
			break;
	}
	XSync(dpy, 0);

	/* did we manage to lock everything? */
	if (nlocks != nscreens)
		return 1;

	/* DPMS magic to disable the monitor */
	if (!DPMSCapable(dpy))
		die("slock: DPMSCapable failed\n");
	if (!DPMSInfo(dpy, &standby, &dpms_state))
		die("slock: DPMSInfo failed\n");
	if (!DPMSEnable(dpy) && !dpms_state)
		die("slock: DPMSEnable failed\n");
	if (!DPMSGetTimeouts(dpy, &standby, &suspend, &off))
		die("slock: DPMSGetTimeouts failed\n");
	if (!standby || !suspend || !off)
		die("slock: at least one DPMS variable is zero\n");
	if (!DPMSSetTimeouts(dpy, monitortime, monitortime, monitortime))
		die("slock: DPMSSetTimeouts failed\n");

	XSync(dpy, 0);

	/* run post-lock command */
	if (argc > 0) {
		switch (fork()) {
		case -1:
			die("slock: fork failed: %s\n", strerror(errno));
		case 0:
			if (close(ConnectionNumber(dpy)) < 0)
				die("slock: close: %s\n", strerror(errno));
			execvp(argv[0], argv);
			fprintf(stderr, "slock: execvp %s: %s\n", argv[0], strerror(errno));
			_exit(1);
		}
	}

	/* everything is now blank. Wait for the correct password */
	readpw(dpy, &rr, locks, nscreens, hash);

	/* reset DPMS values to inital ones */
	DPMSSetTimeouts(dpy, standby, suspend, off);
	if (!dpms_state)
		DPMSDisable(dpy);
	XSync(dpy, 0);

	return 0;
}
