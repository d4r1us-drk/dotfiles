# DRK's dotfiles (suckless)
This repository contains the dotfiles for my dwm (Dynamic Window Manager)
setup. Below are the keybindings and explanations for various actions in dwm.

Feel free to explore the configuration files and adapt them to your
preferences. If you have any questions or suggestions, please open an issue in
this repository.

Enjoy your dwm experience!

## Layouts
These are the supported layots in my dwm build
- Tiled: The default tiling layout.
- Floating: Allows windows to be freely moved and resized.
- Monocle: Maximized layout with the focused window maximized and all other windows behind.
- Centered Master: Master area in the center, slave area on the sides.
- Centered Floating Master: Similar to centered master, but in floating mode.
- Dwindle: Windows are arranged in a spiral pattern.
- Spiral: Similar to dwindle but in the opposite direction.

## Scratchpad Applications
A scratchpad is a convenient way to access and hide frequently used
applications. Applications launched in the scratchpad can be toggled with a
keybinding, making it easy to keep them accessible without cluttering the main
workspace.

The following applications are configured to be launched in the scratchpad:
- Terminal (wezterm)
- System Monitor (btop)
- Audio Mixer (pulsemixer)
- Movies from the terminal (flix-cli)
- Anime from the terminal (ani-cli)
- YouTube videos from the terminal (ytfzf)
- YouTube music from the terminal (ytfzf)
- Music Player (cmus)
- File Manager (vifm)
- News Reader (newsboat)

## Main Configuration Files
- `user/.config/suckless/dwm/config.h`: Main configuration file for dwm.
- `user/.config/suckless/dwm/autostart`: Script to be executed on dwm startup.
- `user/.config/suckless/dmenu/scripts/`: Miscellaneous dmenu scripts used in the setup (these are super useful).
- `user/.config/wezterm/`: Configuration files for the wezterm terminal emulator.
- `user/.config/picom/`: Configuration files for the picom compositor.
- `user/.config/dunst/`: Configuration files for the dunst notification daemon.
- `user/.config/lvim/`: Configuration files for the lunarvim text editor.
- `user/.config/qutebrowser/`: Configuration files for the qutebrowser web browser.
- `user/.config/newsboat/`: Configuration files for the newsboat rss reader.
- `user/.config/vifm/`: Configuration files for the vifm file manager.
- `user/.config/zathura/`: Configuration files for the zathura document viewer.
- `user/.config/mpv/`: Configuration files for the mpv music player.
- `user/.config/btop/`: Configuration files for the btop system monitor.
- `user/.config/gtk-2.0/` & `user/.config/gtk-3.0/`: Configuration files for GTK 2&3.
- `user/.config/Kvantum/`: Configuration files for the Kvantum theme manager for Qt.
- `user/.bashrc/`: Configuration file for the bash shell.
- `user/.bash_profile/`: Another Configuration file for the bash shell.
- `user/.xinitrc/`: X11 startup script.

## Keybindings
### General Keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `MODKEY + Return` | Open terminal (wezterm)  |
| `MODKEY + b` | Toggle the status bar |
| `MODKEY + Control + Shift + q` | Quit dwm |
| `MODKEY + Control + r` | Restart dwm |
| `MODKEY + x, e` | Switch to the Spanish keyboard layout |
| `MODKEY + x, u` | Switch to the US keyboard layout |

### Dmenu keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `MODKEY + p, r` | Open dmenu to run applications |
| `MODKEY + p, d` | Open dmenu to run applications (.desktop files) |
| `MODKEY + p, i` | Open dmenu for Wi-Fi configuration |
| `MODKEY + p, b` | Open dmenu for Bluetooth configuration |
| `MODKEY + p, s` | Open dmenu for taking screenshots |
| `MODKEY + p, w` | Open dmenu for changing the wallpaper |
| `MODKEY + p, q` | Open dmenu for power options |
| `MODKEY + p, e` | Open dmenu for editing files |

### Apps keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `MODKEY + a, e` | Open the editor (lvim) |
| `MODKEY + a, w` | Open the web browser (qutebrowser) |
| `MODKEY + a, c` | Open the chat application (Signal) |
| `MODKEY + a, v` | Open the virtual machine manager (virt-manager) |
| `MODKEY + a, o` | Open the office suite (LibreOffice) |
| `MODKEY + a, k` | Open the video editor (Kdenlive) |
| `MODKEY + a, i` | Open the image editor (GIMP) |
| `MODKEY + a, x` | Open the handwritten note application (Xournalpp) |

### Media keys keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `XF86AudioRaiseVolume` | Increase audio volume |
| `XF86AudioLowerVolume` | Decrease audio volume |
| `XF86AudioMute` | Mute/unmute audio |
| `XF86AudioMicMute` | Mute/unmute microphone |
| `XF86MonBrightnessUp` | Increase screen brightness |
| `XF86MonBrightnessDown` | Decrease screen brightness |
| `XF86Display` | Open display configuration (arandr) |
| `XF86AudioPause` | Pause audio playback |
| `XF86AudioPlay` | Play/pause audio |
| `XF86AudioNext` | Play the next track |
| `XF86AudioPrev` | Play the previous track |
| `XF86AudioStop` | Stop audio playback |
| `XF86News` | Open news reader (newsboat) |


### Window management keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `MODKEY + j` | Focus on the next window |
| `MODKEY + k` | Focus on the previous window |
| `MODKEY + Shift + j` | Move the focused window down in the stack |
| `MODKEY + Shift + k` | Move the focused window up in the stack |
| `MODKEY + i` | Increase the number of master clients |
| `MODKEY + d` | Decrease the number of master clients |
| `MODKEY + h` | Decrease master area size |
| `MODKEY + l` | Increase master area size |
| `MODKEY + Control + Return` | Move focused window to master |
| `MODKEY + Shift + Return` | Focus the master window |
| `MODKEY + Mod1 + Return` | Move the master area to the opposite side |
| `MODKEY + Tab` | Switch to the previously selected tag |
| `MODKEY + q` | Close the focused window |
| `MODKEY + c, t` | Set tiled layout |
| `MODKEY + c, f` | Set floating layout |
| `MODKEY + c, m` | Set monocle layout |
| `MODKEY + c, c` | Set centered master layout |
| `MODKEY + c, v` | Set centered floating master layout |
| `MODKEY + c, d` | Set dwindle layout |
| `MODKEY + c, s` | Set spiral layout |
| `MODKEY + space` | Cycle through available layouts |
| `MODKEY + Control + space` | Cycle through available layouts (in reverse) |
| `MODKEY + Shift + space` | Switch to last used layout |
| `MODKEY + Mod1 + space` | Toggle floating status for the focused window |
| `MODKEY + f` | Toggle fullscreen status for the focused window |
| `MODKEY + 0` | View all tags |
| `MODKEY + Shift + 0` | Tag all windows with the current tag |
| `MODKEY + Comma` | Focus on the previous monitor |
| `MODKEY + Period` | Focus on the next monitor |
| `MODKEY + Shift + Comma` | Move the focused window to the previous monitor |
| `MODKEY + Shift + Period` | Move the focused window to the next monitor |

### Scratchpads Keybindings
| Keybinding | Action                            |
|------------|-----------------------------------|
| `MODKEY + Shift + x + Return` | Launch wezterm (terminal) in scratchpad |
| `MODKEY + x, b` | Launch btop (system monitor) in scratchpad |
| `MODKEY + x, p` | Launch pulsemixer (audio mixer) in scratchpad |
| `MODKEY + x, f` | Launch flix-cli (movies) in scratchpad |
| `MODKEY + x, a` | Launch ani-cli (anime) in scratchpad |
| `MODKEY + x, y` | Launch ytfzf (YouTube videos) in scratchpad |
| `MODKEY + x, n` | Launch ytfzf (YouTube music) in scratchpad |
| `MODKEY + x, m` | Launch cmus (music player) in scratchpad |
| `MODKEY + x, v` | Launch vifm (file manager) in scratchpad |
| `MODKEY + x, r` | Launch newsboat (news reader) in scratchpad |

## Dependencies
This section shows the various dependencies I need for my setup, you don't need
all of them to get everything working, most of them are personal choice. These
commands are for Void Linux only, but you can see the packages you need, so
it's easy to find them for your distribution. All my other applications come
from flatpak.

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
sudo xbps-install -S libvirt virt-manager qemu iptables-nft dnsmasq openbsd-netcat dmidecode podman
```
