#!/bin/bash
house="${HOME}/.config/mwm"
${house}/scripts/ligamento &
sleep 30 &
notify-send "Started all programmes" &
xautolock -time 5 -locker "/home/mauricio/.config/mwm/lock-fusy.sh" -secure -detectsleep &
setxkbmap gb &
