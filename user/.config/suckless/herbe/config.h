static const char *background_color = "#1d2021";
static const char *border_color = "#cc241d";
static const char *font_color = "#fbf1c7";
static const char *font_pattern = "mononoki Nerd Font Mono:size=12";
static const unsigned line_spacing = 5;
static const unsigned int padding = 10;

static const unsigned int width = 400;
static const unsigned int border_size = 1;
static const unsigned int pos_x = 30;
static const unsigned int pos_y = 60;

enum corners { TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT };
enum corners corner = TOP_RIGHT;

static unsigned int duration = 5; /* in seconds */

#define DISMISS_BUTTON Button1
#define ACTION_BUTTON Button3
