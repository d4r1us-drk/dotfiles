local awful = require("awful")
awful.util.spawn_with_shell("$HOME/.fehbg &")
awful.util.spawn_with_shell("lxpolkit &")
awful.util.spawn_with_shell("unclutter --hide-on-touch &")
