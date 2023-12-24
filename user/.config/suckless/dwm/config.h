/* Appearance */
static const unsigned int borderpx    = 1;        /* border pixel of windows */
static const unsigned int snap        = 32;       /* snap pixel */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 1;        /* 0 means bottom bar */
static const int vertpad              = 0;        /* vertical padding of bar */
static const int sidepad              = 0;        /* horizontal padding of bar */
static const int horizpadbar          = 2;        /* horizontal padding for statusbar */
static const int vertpadbar           = 4;        /* vertical padding for statusbar */
static const int rmaster              = 0;        /* 1 means master-area is initially on the left */
static const char *fonts[]            = {"Symbols Nerd Font Mono:size=12", "mononoki Nerd Font:size=12"};
static const char dmenufont[]         = {"mononoki Nerd Font:size=12"};
static const char col_gray1[]         = "#1d2021";
static const char col_gray2[]         = "#32302f";
static const char col_gray3[]         = "#d5c4a1";
static const char col_gray4[]         = "#fbf1c7";
static const char col_cyan[]          = "#cc241d";
static const unsigned int baralpha    = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const XPoint stickyicon[]      = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb      = {4,8};  /* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* Color Definitions */
static const char *colors[][3]        = {
    /*             fg          bg         border  */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel]  = {col_gray4, col_cyan,  col_cyan},
};

static const unsigned int alphas[][3]      = {
    /*             fg       bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel]  = {OPAQUE, baralpha, borderalpha},
};


/* Scratchpad Definitions */
const char *spcmd1[]  = {"st", "-n", "sptrm", "-c", "sptrm", "-g", "140x35", NULL};
const char *spcmd2[]  = {"st", "-n", "sptop", "-c", "sptop", "-g", "140x35", "-e", "btop", NULL};
const char *spcmd3[]  = {"st", "-n", "sppmx", "-c", "sppmx", "-g", "140x35", "-e", "pulsemixer", NULL};
const char *spcmd4[]  = {"st", "-n", "spfli", "-c", "spfli", "-g", "140x35", "-e", "flix-cli", NULL};
const char *spcmd5[]  = {"st", "-n", "spani", "-c", "spani", "-g", "140x35", "-e", "ani-cli", NULL};
const char *spcmd6[]  = {"st", "-n", "spytf", "-c", "spytf", "-g", "140x35", "-e", "ytfzf", "-flstT", "chafa", NULL};
const char *spcmd7[]  = {"st", "-n", "spytm", "-c", "spytm", "-g", "140x35", "-e", "ytfzf", "-mlstT", "chafa", NULL};
const char *spcmd8[]  = {"st", "-n", "spmsc", "-c", "spmsc", "-g", "140x35", "-e", "cmus", NULL};
const char *spcmd9[]  = {"st", "-n", "spflm", "-c", "spflm", "-g", "140x35", "-e", "vifm", NULL};
const char *spcmd10[]  = {"st", "-n", "sprss", "-c", "sprss", "-g", "140x35", "-e", "newsboat", NULL};

static Sp scratchpads[] = {
    /* NAME         CMD */
    {"sptrm",      spcmd1},
    {"sptop",      spcmd2},
    {"sppmx",      spcmd3},
    {"spfli",      spcmd4},
    {"spani",      spcmd5},
    {"spytf",      spcmd6},
    {"spytm",      spcmd7},
    {"spmsc",      spcmd8},
    {"spflm",      spcmd9},
    {"sprss",      spcmd10},
};

/* Tag Definitions */
static const char *tags[] = {
  "",  /* EDITOR */
  "󰙨",  /* TESTING */
  "󰖟",  /* WEB */
  "󰭹",  /* CHAT */
  "󱡭",  /* AUDIO */
  "󰕧",  /* VIDEO */
  "󰏘",  /* GRAPHICS */
  "󰈙",  /* OFFICE */
  "󰊖"   /* GAMES */
};

/* Window Rules */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* CLASS - INSTANCE - TITLE - TAGS MASK - ISFLOATING - MONITOR */
    /* 0 - No Tag */
    {"Galculator",                      NULL,        NULL,         0,   1,   -1},
    {"Qalculate-gtk",                   NULL,        NULL,         0,   1,   -1},
    /* 1 - Code Tag */
    {"editor",                          NULL,        NULL,         1,   0,   -1},
    {"Emacs",                           NULL,        NULL,         1,   0,   -1},
    {"Godot",                           NULL,        NULL,         1,   0,   -1},
    {"neovim",                          NULL,        NULL,         1,   0,   -1},
    {"neovide",                         NULL,        NULL,         1,   0,   -1},
    /* 2 - Test Tag */
    {"Virt-manager",                    NULL,        NULL,    1 << 1,   0,   -1},
    {"Gnome-boxes",                     NULL,        NULL,    1 << 1,   0,   -1},
    /* 3 - Web Tag */
    {"LibreWolf",                       NULL,        NULL,    1 << 2,   0,   -1},
    {"librewolf-default",               NULL,        NULL,    1 << 2,   0,   -1},
    {"firefox",                         NULL,        NULL,    1 << 2,   0,   -1},
    {"qutebrowser",                     NULL,        NULL,    1 << 2,   0,   -1},
    {"Chromium",                        NULL,        NULL,    1 << 2,   0,   -1},
    {"Brave-browser",                   NULL,        NULL,    1 << 2,   0,   -1},
    {"Bitwarden",                       NULL,        NULL,    1 << 2,   0,   -1},
    {"newsboat",                        NULL,        NULL,    1 << 2,   0,   -1},
    /* 4 - Chat Tag */
    {"Signal",                          NULL,        NULL,    1 << 3,   0,   -1},
    /* 5 - Audio Tools Tag */
    {"Audacity",                        NULL,        NULL,    1 << 4,   0,   -1},
    {"Ardour",                          NULL,        NULL,    1 << 4,   0,   -1},
    {"Carla2",                          NULL,        NULL,    1 << 4,   0,   -1},
    {"Carla2-Control",                  NULL,        NULL,    1 << 4,   0,   -1},
    {"QjackCtl",                        NULL,        NULL,    1 << 4,   1,   -1},
    {"lsp-plugins",                     NULL,        NULL,    1 << 4,   1,   -1},
    {"qpwgraph",                        NULL,        NULL,    1 << 4,   0,   -1},
    {"Cadence",                         NULL,        NULL,    1 << 4,   0,   -1},
    {"easyeffects",                     NULL,        NULL,    1 << 4,   0,   -1},
    /* 6 - Video Tag */
    {"kdenlive",                        NULL,        NULL,    1 << 5,   0,   -1},
    {"Pitivi",                          NULL,        NULL,    1 << 5,   0,   -1},
    {"Natron",                          NULL,        NULL,    1 << 5,   0,   -1},
    {"SimpleScreenRecorder",            NULL,        NULL,    1 << 5,   0,   -1},
    {"Ghb",                             NULL,        NULL,    1 << 5,   0,   -1},
    {"obs",                             NULL,        NULL,    1 << 5,   0,   -1},
    {"mpv",                             NULL,        NULL,    1 << 5,   0,   -1},
    /* 7 - Graphics Tools Tag */
    {"Blender",                         NULL,        NULL,    1 << 6,   0,   -1},
    {"Gimp-2.10",                       NULL,        NULL,    1 << 6,   0,   -1},
    {"krita",                           NULL,        NULL,    1 << 6,   0,   -1},
    {"Inkscape",                        NULL,        NULL,    1 << 6,   0,   -1},
    {"Xournalpp",                       NULL,        NULL,    1 << 6,   0,   -1},
    {"Com.github.xournalpp.xournalpp",  NULL,        NULL,    1 << 6,   0,   -1},
    /* 8 - Office Tag */
    {"DesktopEditors",                  NULL,        NULL,    1 << 7,   0,   -1},
    {"Soffice",                         "soffice",   NULL,    1 << 7,   0,   -1},
    {"libreoffice-startcenter",         NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-calc",                NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-writer",              NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-impress",             NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-base",                NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-draw",                NULL,        NULL,    1 << 7,   0,   -1},
    {"libreoffice-math",                NULL,        NULL,    1 << 7,   0,   -1},
    {"Joplin",                          NULL,        NULL,    1 << 7,   0,   -1},
    /* 9 - Games Tag */
    {"retroarch",                       NULL,        NULL,    1 << 8,   0,   -1},
    {"steam",                           NULL,        NULL,    1 << 8,   0,   -1},
    /* Scratchpads */
    {NULL,                              "sptrm",     NULL,    SPTAG(0), 1,   -1},
    {NULL,                              "sptop",     NULL,    SPTAG(1), 1,   -1},
    {NULL,                              "sppmx",     NULL,    SPTAG(2), 1,   -1},
    {NULL,                              "spfli",     NULL,    SPTAG(3), 1,   -1},
    {NULL,                              "spani",     NULL,    SPTAG(4), 1,   -1},
    {NULL,                              "spytf",     NULL,    SPTAG(5), 1,   -1},
    {NULL,                              "spytm",     NULL,    SPTAG(6), 1,   -1},
    {NULL,                              "spmsc",     NULL,    SPTAG(7), 1,   -1},
    {NULL,                              "spflm",     NULL,    SPTAG(8), 1,   -1},
    {NULL,                              "sprss",     NULL,    SPTAG(9), 1,   -1},
};

/* Layout(s) */
static const float mfact          = 0.5;  /* factor of master area size [0.05..0.95] */
static const int   nmaster        = 1;    /* number of clients in master area */
static const int   resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",    tile },    /* first entry is default */
    { "><>",    NULL },
    { "[M]",    monocle },
    { "|||",    centeredmaster },
    { ">|>",    centeredfloatingmaster },
 	{ "[@]",    spiral },
 	{ "[\\]",   dwindle },
    { "HHH",    grid },
	{ NULL,     NULL },
};

/* Key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
        &((Keychord){1, {{MODKEY, KEY}},                                comboview,      {.ui = 1 << TAG} }), \
        &((Keychord){1, {{MODKEY|ControlMask, KEY}},                    toggleview,     {.ui = 1 << TAG} }), \
        &((Keychord){1, {{MODKEY|ShiftMask, KEY}},						combotag,       {.ui = 1 << TAG} }), \
        &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),

/* Helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Main commands */
static const char *dmenucmd[]      = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]       = { "st", NULL };
static const char *editor[]        = { "st", "-n", "editor", "-c", "editor", "-e", ".local/bin/lvim", NULL};
static const char *browser[]       = { "qutebrowser", NULL };
static const char *chat[]          = { "flatpak", "run", "org.signal.Signal", NULL };
static const char *virtuamachine[] = { "virt-manager", NULL };
static const char *office[]        = { "flatpak", "run", "org.libreoffice.LibreOffice", NULL };
static const char *videoeditor[]   = { "flatpak", "run", "org.kde.kdenlive", NULL };
static const char *imgeditor[]     = { "flatpak", "run", "org.gimp.GIMP", NULL };
static const char *handnote[]      = { "flatpak", "run", "com.github.xournalpp.xournalpp", NULL };

/* Keybindings */
static Keychord *keychords[] = {
    /* Keys        function        argument */
    /* Terminal */
    &((Keychord){1, {{MODKEY, XK_Return}},                  spawn,          {.v = termcmd } }),

    /* dmenu */
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_r}},            spawn,          {.v = dmenucmd } }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_d}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_drun") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_i}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_wifi") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_s}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_scrot") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_w}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_wall") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_e}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_edit") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_b}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_blue") }),
    &((Keychord){2, {{MODKEY, XK_p}, {0, XK_q}},            spawn,          SHCMD("$HOME/.config/suckless/dmenu/scripts/dmenu_power") }),

    /* Apps */
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_e}},            spawn,          {.v = editor } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_w}},            spawn,          {.v = browser } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_c}},            spawn,          {.v = chat } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_v}},            spawn,          {.v = virtuamachine } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_o}},            spawn,          {.v = office } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_k}},            spawn,          {.v = videoeditor } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_i}},            spawn,          {.v = imgeditor } }),
    &((Keychord){2, {{MODKEY, XK_a}, {0, XK_x}},            spawn,          {.v = handnote } }),

    /* Keyboard Layouts */
    &((Keychord){2, {{MODKEY, XK_x}, {0, XK_e}},            spawn,          SHCMD("setxkbmap -layout es && pkill -RTMIN+10 dwmblocks") }),
    &((Keychord){2, {{MODKEY, XK_x}, {0, XK_u}},            spawn,          SHCMD("setxkbmap -layout us && pkill -RTMIN+10 dwmblocks") }),

    /* Audio Control */
    &((Keychord){1, {{0, XF86XK_AudioRaiseVolume}},         spawn,          SHCMD("pamixer -i 5 && pkill -RTMIN+10 dwmblocks") }),
    &((Keychord){1, {{0, XF86XK_AudioLowerVolume}},         spawn,          SHCMD("pamixer -d 5 && pkill -RTMIN+10 dwmblocks") }),
    &((Keychord){1, {{0, XF86XK_AudioMute}},                spawn,          SHCMD("pamixer -t && pkill -RTMIN+10 dwmblocks") }),
    &((Keychord){1, {{0, XF86XK_AudioMicMute}},             spawn,          SHCMD("pamixer --default-source -t && pkill -RTMIN+10 dwmblocks") }),

    /* Brightness Control */
    &((Keychord){1, {{0, XF86XK_MonBrightnessUp}},          spawn,          SHCMD("brightnessctl s 5%+ && pkill -RTMIN+10 dwmblocks") }),
    &((Keychord){1, {{0, XF86XK_MonBrightnessDown}},        spawn,          SHCMD("brightnessctl s 5%- && pkill -RTMIN+10 dwmblocks") }),

    /* Display Control */
    &((Keychord){1, {{0, XF86XK_Display}},                  spawn,          SHCMD("arandr") }),

    /* Media Control */
    &((Keychord){1, {{0, XF86XK_AudioPause}},               spawn,          SHCMD("playerctl play-pause") }),
    &((Keychord){1, {{0, XF86XK_AudioPlay}},                spawn,          SHCMD("playerctl play-pause") }),
    &((Keychord){1, {{0, XF86XK_AudioNext}},                spawn,          SHCMD("playerctl next") }),
    &((Keychord){1, {{0, XF86XK_AudioPrev}},                spawn,          SHCMD("playerctl previous") }),
    &((Keychord){1, {{0, XF86XK_AudioStop}},                spawn,          SHCMD("playerctl stop") }),

    /* RSS Feed */
    &((Keychord){1, {{0, XF86XK_News}},                     spawn,          SHCMD("st -n newsboat -c newsboat -e newsboat") }),

    /* Window Management */
    &((Keychord){1, {{MODKEY, XK_j}},                       focusstack,     {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_k}},                       focusstack,     {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_j}},             movestack,      {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_k}},	            movestack,      {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_i}},                       incnmaster,     {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_d}},                       incnmaster,     {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_h}},                       setmfact,       {.f = -0.05} }),
    &((Keychord){1, {{MODKEY, XK_l}},                       setmfact,       {.f = +0.05} }),
    &((Keychord){1, {{MODKEY|ControlMask, XK_Return}},      zoom,           {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Return}},        focusmaster,    {0} }),
    &((Keychord){1, {{MODKEY|Mod1Mask, XK_Return}},         togglemaster,   {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Tab}},           togglesticky,   {0} }),
    &((Keychord){1, {{MODKEY, XK_Tab}},                     view,           {0} }),
    &((Keychord){1, {{MODKEY, XK_q}},                       killclient,     {0} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_t}},            setlayout,      {.v = &layouts[0]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_f}},            setlayout,      {.v = &layouts[1]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_m}},            setlayout,      {.v = &layouts[2]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_c}},            setlayout,      {.v = &layouts[3]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_v}},            setlayout,      {.v = &layouts[4]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_d}},            setlayout,      {.v = &layouts[5]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_s}},            setlayout,      {.v = &layouts[6]} }),
    &((Keychord){2, {{MODKEY, XK_c}, {0, XK_g}},            setlayout,      {.v = &layouts[7]} }),
    &((Keychord){1, {{MODKEY, XK_f}},                       fullscreen,     {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_space}},         setlayout,      {0} }),
    &((Keychord){1, {{MODKEY, XK_space}},                   cyclelayout,    {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ControlMask, XK_space}},       cyclelayout,    {.i = +1 } }),
    &((Keychord){1, {{MODKEY|Mod1Mask, XK_space}},          togglefloating, {0} }),
    &((Keychord){1, {{MODKEY, XK_0}},                       view,           {.ui = ~0 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_0}},             tag,            {.ui = ~0 } }),
    &((Keychord){1, {{MODKEY, XK_comma}},                   focusmon,       {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_period}},                  focusmon,       {.i = +1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_comma}},         tagmon,         {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_period}},        tagmon,         {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_b}},                       togglebar,      {0} }),

    /* Scratchpads */
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_Return}},       togglescratch,  {.ui = 0 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_b}},            togglescratch,  {.ui = 1 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_p}},  	        togglescratch,  {.ui = 2 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_f}},  	        togglescratch,  {.ui = 3 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_a}},  	        togglescratch,  {.ui = 4 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_y}},  	        togglescratch,  {.ui = 5 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_n}},  	        togglescratch,  {.ui = 6 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_m}},  	        togglescratch,  {.ui = 7 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_v}},  	        togglescratch,  {.ui = 8 } }),
    &((Keychord){2, {{MODKEY, XK_s}, {0, XK_r}},  	        togglescratch,  {.ui = 9 } }),

    /* Session Management */
    &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, XK_q}}, quit,           {0} }), 
    &((Keychord){1, {{MODKEY|ControlMask, XK_r}},           quit,           {1} }),

    /* Tag Keys */
    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
};

/* Mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

/* Resizemousescroll direction argument list */
static const int scrollargs[][2] = {
    /* width change         height change */
    { +scrollsensetivity,	0 },
    { -scrollsensetivity,	0 },
    { 0, 				  	+scrollsensetivity },
    { 0, 					-scrollsensetivity },
};

/* Mouse Bindings */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         MODKEY,         Button4,        resizemousescroll, {.v = &scrollargs[0]} },
    { ClkClientWin,         MODKEY,         Button5,        resizemousescroll, {.v = &scrollargs[1]} },
    { ClkClientWin,         MODKEY,         Button6,        resizemousescroll, {.v = &scrollargs[2]} },
    { ClkClientWin,         MODKEY,         Button7,        resizemousescroll, {.v = &scrollargs[3]} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


