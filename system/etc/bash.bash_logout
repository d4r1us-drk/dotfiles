#!/usr/bin/env bash
# ~/.bash_logout: executed by bash(1) when login shell exits.

if [ "$SHLVL" = 1 ]; then
	[ -x /usr/bin/clear ] && /usr/bin/clear -q
fi
