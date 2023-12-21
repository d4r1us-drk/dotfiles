local wezterm = require 'wezterm'
local gpus = wezterm.gui.enumerate_gpus()

return {
    enable_wayland = false,
    font = wezterm.font {
        family = 'mononoki Nerd Font',
        weight = 'Medium'
    },
    color_scheme = 'Gruvbox dark, hard (base16)',
    default_prog = { '/usr/bin/bash' },
    default_cursor_style = "BlinkingUnderline",
    font_size = 12,
    check_for_updates = false,
    use_dead_keys = false,
    warn_about_missing_glyphs = false,
    enable_kitty_graphics = true,
    animation_fps = 1,
    cursor_blink_rate = 175,
    hide_tab_bar_if_only_one_tab = true,
    adjust_window_size_when_changing_font_size = false,
    window_padding = {
        left = 10,
        right = 10,
        top = 10,
        bottom = 10,
    },
    use_fancy_tab_bar = false,
    exit_behavior = "Close",
    window_close_confirmation = 'NeverPrompt',
    tab_bar_at_bottom = false,
    window_background_opacity = 0.98,
    initial_rows = 40,
    initial_cols = 130,
}
