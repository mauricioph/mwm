#!/bin/bash
house="${HOME}/.config/mwm"
"${house}/scripts/ligamento" &
compton -i $HOME/.config/compton.conf &
/usr/local/bin/wallpaper.script &
play /usr/share/sounds/Ps1\ startup\ sound.flac &
sleep 30 &
notify-send "Started all programmes" &
