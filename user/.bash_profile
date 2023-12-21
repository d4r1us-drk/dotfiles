#!/bin/bash
##       ____             __
##      / __ \_________ _/ /_____
##     / / / / ___/ __ `/ //_/ _ \
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)
##   /_____/_/   \__,_/_/|_|\___/   My custom bash_profile config
##

# starting xsession
if [ -z "$DISPLAY" ] && [ "$(tty)" = "/dev/tty1" ]; then
  startx -- vt1 -keeptty &>/dev/null
  logout
fi

# User defined enviroment variables
export EDITOR="$HOME/.local/bin/lvim"
export VISUAL="$HOME/.local/bin/neovide"
export BROWSER=qutebrowser
export VIEWER=zathura

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
export LESSHISTFILE=-
if [ ! -d "$HOME/.config/wget/" ] && [ ! -d "$GNUPGHOME" ]; then
    mkdir -p "$HOME/.config/wget/" "$GNUPGHOME"
fi

# bashrc
source "$HOME"/.bashrc
