static char delim = '|'; /* sets delimeter between status commands. NULL character ('\0') means no delimeter. */

static const Block blocks[] = {
	/* Command */                                                       /* Update Interval */    /* Update Signal */
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_layout",           0,                      10},
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_battery",          10,                      1},
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_brightness",       0,                      10},
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_volume",           0,                      10},
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_clock",            60,                      1},
	{"", "$HOME/.config/suckless/dwmblocks/scripts/block_wifi",             20,                       1},
};

