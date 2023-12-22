#!/bin/bash
##       ____             __
##      / __ \_________ _/ /_____
##     / / / / ___/ __ `/ //_/ _ \
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)
##   /_____/_/   \__,_/_/|_|\___/   My custom bash_profile config
##
#
# Starting xsession
if [ -z "$DISPLAY" ] && [ "$(tty)" = "/dev/tty1" ]; then
    startx -- vt1 -keeptty &>/dev/null
    logout
fi

# Home folders
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export XDG_CONFIG_HOME="$HOME/.config"

# Sanely export XDG Base dir variables
eval "$(sed 's/^[^#].*/export &/g;t;d' ~/.config/user-dirs.dirs)"

# Clean home
export W3M_DIR="$XDG_DATA_HOME/w3m"
export GTK2_RC_FILES="$HOME/.config/gtk-2.0/gtkrc-2.0"
export WGETRC="$HOME/.config/wget/wgetrc"
export INPUTRC="$HOME/.config/inputrc"
export GNUPGHOME="$HOME/.local/share/gnupg"
export LESSHISTFILE="-"

# Create GNUPG & WGETRC directories if they don't exist
if [ ! -d "$HOME/.config/wget/" ] && [ ! -d "$GNUPGHOME" ]; then
    mkdir -p "$HOME/.config/wget/" "$GNUPGHOME"
fi

# Default apps
export TERMINAL="wezterm"
export EDITOR="$HOME/.local/bin/lvim"
export VISUAL="$TERMINAL start --class editor $EDITOR"
export BROWSER="qutebrowser"
export VIEWER="zathura"

# Bashrc
source "$HOME"/.bashrc
