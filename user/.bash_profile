#!/bin/bash
##       ____             __
##      / __ \_________ _/ /_____
##     / / / / ___/ __ `/ //_/ _ \
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)
##   /_____/_/   \__,_/_/|_|\___/   My custom bash_profile config
##

### STARTING XSESSION
if [ -z "$DISPLAY" ] && [ "$(tty)" = "/dev/tty1" ]
then
  sh $HOME/.winitrc
  logout
fi

# environment variables
export EDITOR="emacsclient -t -a ''"
export VISUAL="emacsclient -c -a 'emacs'"

# clean home
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export XDG_CONFIG_HOME="$HOME/.config"
export W3M_DIR="$XDG_DATA_HOME/w3m"
export GTK2_RC_FILES="$HOME/.config/gtk-2.0/gtkrc-2.0"
export WGETRC="$HOME/.config/wget/wgetrc"
export INPUTRC="$HOME/.config/inputrc"
export GNUPGHOME="$HOME/.local/share/gnupg"
export LESSHISTFILE=-

### BASHRC
source "$HOME"/.bashrc                                           # Load the bashrc
