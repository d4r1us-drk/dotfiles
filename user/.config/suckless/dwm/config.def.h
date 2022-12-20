/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 1;        /* vertical padding for statusbar */
static const char *fonts[]          = {"mononoki Nerd Font Mono:size=10"};
static const char dmenufont[]       = "mononoki Nerd Font Mono:size=10";
static const char col_gray1[]       = "#1d2021";
static const char col_gray2[]       = "#32302f";
static const char col_gray3[]       = "#d5c4a1";
static const char col_gray4[]       = "#fbf1c7";
static const char col_cyan[]        = "#cc241d";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

// SCRATCHPADS
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "-t", "sptrm", "--class", "sptrm,sptrm", NULL };
const char *spcmd2[] = {"alacritty", "-t", "sptop", "--class", "sptop,sptop", "-e", "btop", NULL };
const char *spcmd3[] = {"alacritty", "-t", "spfli", "--class", "spfli,spfli", "-e", "flix-cli", NULL };
const char *spcmd4[] = {"alacritty", "-t", "spani", "--class", "spani,spani", "-e", "ani-cli", NULL };
const char *spcmd5[] = {"alacritty", "-t", "spytf", "--class", "spytf,spytf", "-e", "ytfzf", "-flst", NULL };
const char *spcmd6[] = {"alacritty", "-t", "spamx", "--class", "spamx,spamx", "-e", "alsamixer", NULL };
const char *spcmd7[] = {"alacritty", "-t", "sppmx", "--class", "sppmx,sppmx", "-e", "pulsemixer", NULL };
const char *spcmd8[] = {"alacritty", "-t", "spcht", "--class", "spcht,spcht", "-e", "gomuks", NULL };
const char *spcmd9[] = {"alacritty", "-t", "spmsc", "--class", "spmsc,spmsc", "-e", "cmus", NULL };
const char *spcmd10[] = {"alacritty", "-t", "spflm", "--class", "spflm,spflm", "-e", "./.config/vifm/scripts/vifmrun", NULL };
const char *spcmd11[] = {"alacritty", "-t", "sptot", "--class", "sptot,sptot", "-e", "toot", "tui", NULL };
const char *spcmd12[] = {"alacritty", "-t", "spytm", "--class", "spytm,spytm", "-e", "ytfzf", "-mlst", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"sptrm",      spcmd1},
	{"sptop",      spcmd2},
	{"spfli",      spcmd3},
	{"spani",      spcmd4},
	{"spytf",      spcmd5},
	{"spamx",      spcmd6},
	{"sppmx",      spcmd7},
	{"spcht",      spcmd8},
	{"spmsc",      spcmd9},
	{"spflm",      spcmd10},
	{"sptot",      spcmd11},
	{"spytm",      spcmd12},
};

/* tagging */
static const char *tags[] = {
        "cde", // EDITOR
        "tst",  // FILE MANAGER
        "web", // WEB BROWSER
        "aud",  // CHAT
        "tls",  // MUSIC
        "vid", // VIDEO
        "gfx",  // IMAGE/EDIT TOOLS
        "off",  // OFFICE
        "gme"   // GAMES
};

// RULES
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	// class                           instance                 title       tags mask     isfloating   monitor
	// no workspace
	{ "Galculator",                       NULL,                 NULL,              0,       1,           -1 },
	// code tag
	{ "Emacs",                            NULL,                 NULL,              1,       0,           -1 },
	{ "Godot",                            NULL,                 NULL,              1,       0,           -1 },
	{ "neovim",                           NULL,                 NULL,              1,       0,           -1 },
	{ "neovide",                          NULL,                 NULL,              1,       0,           -1 },
	// test tag
	{ "Virt-manager",                     NULL,                 NULL,              1,       0,           -1 },
	// web tag
	{ "librewolf",                        NULL,                 NULL,         1 << 2,       0,           -1 },
	{ "firefox",                          NULL,                 NULL,         1 << 2,       0,           -1 },
	{ "qutebrowser",                      NULL,                 NULL,         1 << 2,       0,           -1 },
	{ "Chromium",                         NULL,                 NULL,         1 << 2,       0,           -1 },
	{ "Brave-browser",                    NULL,                 NULL,         1 << 2,       0,           -1 },
	{ "Bitwarden",                        NULL,                 NULL,         1 << 2,       0,           -1 },
	// audio tag
	{ "Audacity",                         NULL,                 NULL,         1 << 3,       0,           -1 },
	{ "Ardour",                           NULL,                 NULL,         1 << 3,       0,           -1 },
	{ "Carla2",                           NULL,                 NULL,         1 << 3,       0,           -1 },
	{ "Carla2-Control",                   NULL,                 NULL,         1 << 3,       0,           -1 },
	// audio tools tag
	{ "QjackCtl",                         NULL,                 NULL,         1 << 4,       1,           -1 },
	{ "lsp-plugins",                      NULL,                 NULL,         1 << 4,       1,           -1 },
	{ "qpwgraph",                         NULL,                 NULL,         1 << 4,       0,           -1 },
	{ "Cadence",                          NULL,                 NULL,         1 << 4,       0,           -1 },
	// video tag
	{ "kdenlive",                         NULL,                 NULL,         1 << 5,       0,           -1 },
	{ "Blender",                          NULL,                 NULL,         1 << 5,       0,           -1 },
	{ "Natron",                           NULL,                 NULL,         1 << 5,       0,           -1 },
	{ "SimpleScreenRecorder",             NULL,                 NULL,         1 << 5,       0,           -1 },
	{ "Ghb",                              NULL,                 NULL,         1 << 5,       0,           -1 },
	{ "obs",                              NULL,                 NULL,         1 << 5,       0,           -1 },
	// graphics/extra tools tag
	{ "Gimp-2.10",                        NULL,                 NULL,         1 << 6,       0,           -1 },
	{ "krita",                            NULL,                 NULL,         1 << 6,       0,           -1 },
	{ "Inkscape",                         NULL,                 NULL,         1 << 6,       0,           -1 },
	{ "Xournalpp",                        NULL,                 NULL,         1 << 6,       0,           -1 },
	// office tag
	{ "DesktopEditors",                   NULL,                 NULL,         1 << 7,       0,           -1 },
	{ "Soffice",                          "soffice",            NULL,         1 << 7,       0,           -1 },
	{ "libreoffice-startcenter",          NULL,                 NULL,         1 << 7,       0,           -1 },
	{ "Joplin",                           NULL,                 NULL,         1 << 7,       0,           -1 },
	// games tag
	{ "retroarch",                        NULL,                 NULL,         1 << 8,       0,           -1 },
	{ "steam",                            NULL,                 NULL,         1 << 8,       0,           -1 },
	// scratchpads
	{ NULL,                            "sptrm",                 NULL,       SPTAG(0),       1,           -1 },
	{ NULL,                            "sptop",                 NULL,       SPTAG(1),       1,           -1 },
	{ NULL,                            "spfli",                 NULL,       SPTAG(2),       1,           -1 },
	{ NULL,                            "spani",                 NULL,       SPTAG(3),       1,           -1 },
	{ NULL,                            "spytf",                 NULL,       SPTAG(4),       1,           -1 },
	{ NULL,                            "spamx",                 NULL,       SPTAG(5),       1,           -1 },
	{ NULL,                            "sppmx",                 NULL,       SPTAG(6),       1,           -1 },
	{ NULL,                            "spcht",                 NULL,       SPTAG(7),       1,           -1 },
	{ NULL,                            "spmsc",                 NULL,       SPTAG(8),       1,           -1 },
	{ NULL,                            "spflm",                 NULL,       SPTAG(9),       1,           -1 },
	{ NULL,                            "sptot",                 NULL,       SPTAG(10),       1,           -1 },
	{ NULL,                            "spytm",                 NULL,       SPTAG(11),       1,           -1 },
};

// layout(s)
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "tcl.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|||",      tcl },
};

//key definitions
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// dmenu
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
// terminal
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	// text editor
	{ MODKEY,                       XK_e,                      spawn,          SHCMD("emacsclient -c -a 'emacs'")},
	// web browser
	{ MODKEY,                       XK_w,                      spawn,          SHCMD("qutebrowser")},
	// set keyboard layout to es
	{ MODKEY|ControlMask,           XK_e,                      spawn,          SHCMD("setxkbmap -layout es")},
	// set keyboard layout to us
	{ MODKEY|ControlMask,           XK_u,                      spawn,          SHCMD("setxkbmap -layout us")},
	// increase volume
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          SHCMD("pamixer -i 5")},
	// decrease volume
	{ 0,                            XF86XK_AudioLowerVolume,   spawn,          SHCMD("pamixer -d 5")},
	// mute volume
	{ 0,                            XF86XK_AudioMute,          spawn,          SHCMD("pamixer -t")},
	// mute microphone
	{ 0,                            XF86XK_AudioMicMute,       spawn,          SHCMD("pamixer --default-source -t")},
	// increase brightness
	{ 0,                            XF86XK_MonBrightnessUp,    spawn,          SHCMD("xbacklight -inc 10")},
	// decrease brightness
	{ 0,                            XF86XK_MonBrightnessDown,  spawn,          SHCMD("xbacklight -dec 10")},
	// decrease brightness
	{ 0,                            XF86XK_Display,            spawn,          SHCMD("arandr")},
	// launcher
	{ MODKEY|ControlMask,           XK_p,      spawn,          {.v = dmenucmd } },
	// desktop launcher
	{ MODKEY,                       XK_p,      spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_drun") },
	// wifi config
	{ MODKEY|Mod1Mask,              XK_i,      spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_wifi") },
	// screenshots
	{ MODKEY|Mod1Mask,              XK_s,      spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_scrot") },
	// screenshots
	{ MODKEY|Mod1Mask,              XK_w,      spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_wall") },
	// edit
	{ MODKEY|Mod1Mask,              XK_e,      spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_edit") },
	// terminal
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	// toogle the bar
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	// window focusing
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	// increase and decrease master clients count
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	// increase and decrease master client size
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	// switch master window
	{ MODKEY|ControlMask,           XK_Return, zoom,           {0} },
	// switch to latest tag
	{ MODKEY,                       XK_Tab,    view,           {0} },
	// close focused client
	{ MODKEY,                       XK_q,      killclient,     {0} },
	// switch to tiling layout
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	// switch to floating layout
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	// switch to monocle layout
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	// switch to three-column layout
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[3]} },
	// switch to latest layout
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	// toggle floating mode on focused window
	{ MODKEY|ControlMask,           XK_space,  togglefloating, {0} },
	// view all opened clients on current tag
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	// focus next or previous screen
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	// move focused client to next or previous screen
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	// scratchpads
	{ MODKEY|ShiftMask,             XK_Return,      togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_b,      togglescratch,  {.ui = 1 } },
	{ MODKEY|ShiftMask,             XK_f,      togglescratch,  {.ui = 2 } },
	{ MODKEY|ShiftMask,             XK_a,      togglescratch,  {.ui = 3 } },
	{ MODKEY|ShiftMask,             XK_y,      togglescratch,  {.ui = 4 } },
	{ MODKEY|ShiftMask,             XK_o,      togglescratch,  {.ui = 5 } },
	{ MODKEY|ShiftMask,             XK_p,      togglescratch,  {.ui = 6 } },
	{ MODKEY|ShiftMask,             XK_c,      togglescratch,  {.ui = 7 } },
	{ MODKEY|ShiftMask,             XK_m,      togglescratch,  {.ui = 8 } },
	{ MODKEY|ShiftMask,             XK_v,      togglescratch,  {.ui = 9 } },
	{ MODKEY|ShiftMask,             XK_t,      togglescratch,  {.ui = 10 } },
	{ MODKEY|ShiftMask,             XK_n,      togglescratch,  {.ui = 11 } },
	// tag bindings
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	// logout
	//{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      spawn,           SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_power")},
	// restart dwm
	{ MODKEY|ControlMask,           XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
// mouse bindings
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

