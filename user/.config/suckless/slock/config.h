static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1d2021",   /* after initialization */
	[INPUT] =  "#076678",   /* during input */
	[FAILED] = "#cc241d",   /* wrong password */
	[CAPS] =   "#fb4934",   /* capsLock on */
	[PAM] =    "#32302f",   /* waiting for PAM */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* PAM service that's used for authentication */
static const char* pam_service = "login";

/* time in seconds before the monitor shuts down */
static const int monitortime = 5;

/* background image path, should be available to the user above */
static const char* background_image = ".config/suckless/slock/lockscreen.png";
