##       ____             __
##      / __ \_________ _/ /_____
##     / / / / ___/ __ `/ //_/ _ \
##    / /_/ / /  / /_/ / ,< /  __/  Clay Gomera (Drake)
##   /_____/_/   \__,_/_/|_|\___/   My custom bash config
##

### EXPORT ###
export TERM="xterm-256color"                      # getting proper colors
export HISTCONTROL=ignoredups:erasedups           # no duplicate entries

### "bat" as manpager
export MANPAGER="sh -c 'col -bx | bat -l man -p'"

# use bash-completion, if available
[[ $PS1 && -f /usr/share/bash-completion/bash_completion ]] && \
    . /usr/share/bash-completion/bash_completion

# if not running interactively, don't do anything
[[ $- != *i* ]] && return

### SET VI MODE ###
# Comment this line out to enable default emacs-like bindings
set -o vi
bind -m vi-command 'Control-l: clear-screen'
bind -m vi-insert 'Control-l: clear-screen'

### PATH ###
if [ -d "$HOME/.bin" ] ;
  then PATH="$HOME/.bin:$PATH"
fi
if [ -d "$HOME/.local/bin" ] ;
  then PATH="$HOME/.local/bin:$PATH"
fi
if [ -d "$HOME/Applications" ] ;
  then PATH="$HOME/Applications:$PATH"
fi

### CHANGE TITLE OF TERMINALS ###
case ${TERM} in
  xterm*|rxvt*|Eterm*|aterm|kterm|gnome*|alacritty|st|konsole*)
    PROMPT_COMMAND='echo -ne "\033]0;${USER}@${HOSTNAME%%.*}:${PWD/#$HOME/\~}\007"'
        ;;
  screen*)
    PROMPT_COMMAND='echo -ne "\033_${USER}@${HOSTNAME%%.*}:${PWD/#$HOME/\~}\033\\"'
    ;;
esac

### SHOPT ###
shopt -s autocd # change to named directory
shopt -s cdspell # autocorrects cd misspellings
shopt -s cmdhist # save multi-line commands in history as single line
shopt -s dotglob
shopt -s histappend # do not overwrite history
shopt -s expand_aliases # expand aliases
shopt -s checkwinsize # checks term size when bash regains control

# ignore upper and lowercase when TAB completion
bind "set completion-ignore-case on"

# sudo not required for some system commands
for command in cryptsetup mount umount poweroff reboot ; do
alias $command="sudo $command"
done; unset command

### ARCHIVE EXTRACTION ###
# usage: ex <file>
ex ()
{
  if [ -f "$1" ] ; then
    case $1 in
      *.tar.bz2)   tar xjf "$1"   ;;
      *.tar.gz)    tar xzf "$1"   ;;
      *.bz2)       bunzip2 "$1"   ;;
      *.rar)       unrar x "$1"   ;;
      *.gz)        gunzip "$1"    ;;
      *.tar)       tar xf "$1"    ;;
      *.tbz2)      tar xjf "$1"   ;;
      *.tgz)       tar xzf "$1"   ;;
      *.zip)       unzip "$1"     ;;
      *.Z)         uncompress "$1";;
      *.7z)        7zz x "$1"     ;;
      *.deb)       ar x "$1"      ;;
      *.tar.xz)    tar xf "$1"    ;;
      *.tar.zst)   unzstd "$1"    ;;
      *)           echo "'$1' cannot be extracted via ex()" ;;
    esac
  else
    echo "'$1' is not a valid file"
  fi
}

### ALIASES ###
# navigation
up () {
  local d=""
  local limit="$1"

  # Default to limit of 1
  if [ -z "$limit" ] || [ "$limit" -le 0 ]; then
    limit=1
  fi

  for ((i=1;i<=limit;i++)); do
    d="../$d"
  done

  # perform cd. Show error if cd fails
  if ! cd "$d"; then
    echo "Couldn't go up $limit dirs.";
  fi
}

# cd
alias \
  ..="cd .." \
  .2="cd ../.." \
  .3="cd ../../.." \
  .4="cd ../../../.." \
  .5="cd ../../../../.."

# bat as cat
[ -x "$(command -v bat)" ] && alias cat="bat"

# use lunarvim for vim if present.
[ -x "$(command -v $HOME/.local/bin/lvim)" ] && alias vim="$HOME/.local/bin/lvim"

# Changing "ls" to "eza"
alias \
  ls="eza --icons -al --color=always --group-directories-first" \
  la="eza --icons -a --color=always --group-directories-first" \
  ll="eza --icons -l --color=always --group-directories-first" \
  lt="eza --icons -aT --color=always --group-directories-first" \
  l.='eza --icons -a | grep -E "^\."'

# function to detect os and assign aliases to package managers
alias \
  xb-up="sudo xbps-install -Su && xcheckrestart" \
  xb-get="sudo xbps-install -S" \
  xb-rmv="sudo xbps-remove -R" \
  xb-rmv-sec="sudo xbps-remove" \
  xb-qry="sudo xbps-query -Rs" \
  xb-cln="sudo xbps-remove -Oo"

# colorize grep output (good for log files)
alias \
  grep="grep --color=auto" \
  egrep="egrep --color=auto" \
  fgrep="fgrep --color=auto"

# git
alias \
  git-adu="git add -u" \
  git-adl="git add ." \
  git-brn="git branch" \
  git-chk="git checkout" \
  git-cln="git clone" \
  git-cmt="git commit -m" \
  git-fth="git fetch" \
  git-pll="git pull origin" \
  git-psh="git push origin" \
  git-sts="git status" \
  git-tag="git tag" \
  git-ntg="git tag -a"

# adding flags
alias \
  df="df -h" \
  free="free -m"

# multimedia scripts
alias \
  fli="flix-cli" \
  ani="ani-cli" \
  aniq="ani-cli -q"

# audio
alias \
  mx="pulsemixer" \
  mk="cmus" \
  ms="cmus" \
  music="cmus"

# power management
alias \
  po="loginctl poweroff" \
  sp="loginctl suspend" \
  rb="loginctl reboot"

# file management
alias \
  fm="vifm" \
  flm="vifm" \
  rm="rm -vI" \
  mv="mv -iv" \
  cp="cp -iv" \
  mkd="mkdir -pv"

# ps
alias \
  psa="ps auxf" \
  psgrep="ps aux | grep -v grep | grep -i -e VSZ -e" \
  psmem="ps auxf | sort -nr -k 4" \
  pscpu="ps auxf | sort -nr -k 3"

# youtube
alias \
  yta-aac="yt-dlp --extract-audio --audio-format aac" \
  yta-best="yt-dlp --extract-audio --audio-format best" \
  yta-flac="yt-dlp --extract-audio --audio-format flac" \
  yta-m4a="yt-dlp --extract-audio --audio-format m4a" \
  yta-mp3="yt-dlp --extract-audio --audio-format mp3" \
  yta-opus="yt-dlp --extract-audio --audio-format opus" \
  yta-vorbis="yt-dlp --extract-audio --audio-format vorbis" \
  yta-wav="yt-dlp --extract-audio --audio-format wav" \
  ytv-best="yt-dlp -f bestvideo+bestaudio" \
  yt="ytfzf -ftsl" \
  ytm="ytfzf -mtsl"

# network and bluetooth
alias \
  netstats="nmcli dev" \
  wfi="nmtui-connect" \
  wfi-scan="nmcli dev wifi rescan && nmcli dev wifi list" \
  wfi-edit="nmtui-edit" \
  wfi-on="nmcli radio wifi on" \
  wfi-off="nmcli radio wifi off" \
  blt="bluetoothctl"

# get current branch in git repo
function parse_git_branch() {
  BRANCH=$(git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1/')
	if [ ! "${BRANCH}" == "" ]
	then
    STAT=$(parse_git_dirty)
		echo "[${BRANCH}${STAT}]"
	else
		echo ""
	fi
}

# get current branch in git repo
function parse_git_branch() {
  BRANCH=$(git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1/')
	if [ ! "${BRANCH}" == "" ]
	then
    STAT=$(parse_git_dirty)
		echo "[${BRANCH}${STAT}]"
	else
		echo ""
	fi
}

# get current status of git repo
function parse_git_dirty {
  status=$(git status 2>&1 | tee)
  dirty=$(echo -n "${status}" 2> /dev/null | grep "modified:" &> /dev/null; echo "$?")
  untracked=$(echo -n "${status}" 2> /dev/null | grep "Untracked files" &> /dev/null; echo "$?")
  ahead=$(echo -n "${status}" 2> /dev/null | grep "Your branch is ahead of" &> /dev/null; echo "$?")
  newfile=$(echo -n "${status}" 2> /dev/null | grep "new file:" &> /dev/null; echo "$?")
  renamed=$(echo -n "${status}" 2> /dev/null | grep "renamed:" &> /dev/null; echo "$?")
  deleted=$(echo -n "${status}" 2> /dev/null | grep "deleted:" &> /dev/null; echo "$?")
	bits=''
	if [ "${renamed}" == "0" ]; then
		bits=">${bits}"
	fi
	if [ "${ahead}" == "0" ]; then
		bits="*${bits}"
	fi
	if [ "${newfile}" == "0" ]; then
		bits="+${bits}"
	fi
	if [ "${untracked}" == "0" ]; then
		bits="?${bits}"
	fi
	if [ "${deleted}" == "0" ]; then
		bits="x${bits}"
	fi
	if [ "${dirty}" == "0" ]; then
		bits="!${bits}"
	fi
	if [ ! "${bits}" == "" ]; then
		echo " ${bits}"
	else
		echo ""
	fi
}

export PS1="[\[\e[31m\]\u\[\e[m\]\[\e[35m\]@\[\e[m\]\[\e[32m\]\h\[\e[m\]] [\[\e[33m\]\W\[\e[m\]\[\e[34m\]\`parse_git_branch\`\[\e[m\]] 󱞪 "
