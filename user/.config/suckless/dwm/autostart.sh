#!/bin/sh
##       ____             __                               ##
##      / __ \_________ _/ /_____                          ##
##     / / / / ___/ __ `/ //_/ _ \                         ##
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)    ##
##   /_____/_/   \__,_/_/|_|\___/   My custom dwm build    ##

lxsession &
dwmblocks &
sh "$HOME"/.fehbg &
picom --config ~/.config/picom/picom.conf &
dunst --config ~/.config/dunst/dunstrc &
/usr/bin/emacs --daemon &
