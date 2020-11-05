#!/bin/bash
house="${HOME}/.config/mwm"
"${house}/scripts/ligamento" &
/usr/local/bin/wallpaper.script &
sleep 30 &
notify-send "Started all programmes" &
