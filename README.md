# Suckless Voidrice
This is my daily driver rice with DWM and suckless programs.

## Dependencies
### System dependencies
``` sh
sudo xbps-install -S git curl wget pipewire wireplumber power-profiles-daemon python3-gobject bluez bluez-alsa flatpak vim neovim udisks2
```

### Xorg dependencies
``` sh
sudo xbps-install -S xorg-server setxkbmap xclip xev xprop xinit xorg-input-drivers libX11 libX11-devel libXinerama libXinerama-devel libXft libXft-devel libXrandr libXrandr-devel imlib2 imlib2-devel harfbuzz harfbuzz-devel
```

### Extra dependencies
``` sh
sudo xbps-install -S brightnessctl picom pamixer pulsemixer fd ripgrep jq fzf eza bat arandr playerctl nerd-fonts noto-fonts-ttf noto-fonts-ttf-extra noto-fonts-cjk noto-fonts-emoji cantarell-fonts newsboat vifm cmus cmus-ffmpeg kvantum gtk-engine-murrine zathura zathura-pdf-poppler j4-dmenu-desktop maim slop feh nsxiv chafa dunst xdpyinfo xdotool
```

### Dev dependencies
``` sh
sudo xbps-install -S base-devel cmake clang llvm rust nodejs vala
```

### VMs & Containers dependencies
``` sh
sudo xbps-install -S libvirt virt-manager iptables-nft dnsmasq openbsd-netcat dmidecode podman
```
