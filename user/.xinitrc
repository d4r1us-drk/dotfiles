#!/bin/sh
##       ____             __
##      / __ \_________ _/ /_____
##     / / / / ___/ __ `/ //_/ _ \
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)
##   /_____/_/   \__,_/_/|_|\___/   My custom xinitrc
##

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps
if [ -f $sysresources ]; then
    xrdb -merge $sysresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then
    xrdb -merge "$userresources"
fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# environment variables
export MOZ_USE_XINPUT2=1
export QT_STYLE_OVERRIDE=kvantum
export XDG_SESSION_TYPE=X11

# clean home
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export XDG_CONFIG_HOME="$HOME/.config"
export XDG_DESKTOP_DIR="$HOME/var/desktop"
export XDG_DOWNLOAD_DIR="$HOME/var/downloads"
export XDG_TEMPLATES_DIR="$HOME/media/documents/templates"
export XDG_PUBLICSHARE_DIR="$HOME/var/public"
export XDG_DOCUMENTS_DIR="$HOME/media/documents"
export XDG_MUSIC_DIR="$HOME/media/music"
export XDG_PICTURES_DIR="$HOME/media/pictures"
export XDG_VIDEOS_DIR="$HOME/media/videos"
export W3M_DIR="$XDG_DATA_HOME/w3m"
export GTK2_RC_FILES="$HOME/.config/gtk-2.0/gtkrc-2.0"
export WGETRC="$HOME/.config/wget/wgetrc"
export INPUTRC="$HOME/.config/inputrc"
export GNUPGHOME="$HOME/.local/share/gnupg"
export LESSHISTFILE="-"

# default apps
export EDITOR="~/.local/bin/lvim"
export VISUAL="neovide --neovim-bin $EDITOR"
export BROWSER="qutebrowser"
export VIEWER="zathura"

# start window manager / desktop environment
dbus-launch dwm
