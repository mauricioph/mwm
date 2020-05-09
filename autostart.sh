#!/bin/bash
house="${HOME}/.config/dwm"
"${house}/dwmstatus" &
compton -i $HOME/.config/compton.conf &
/usr/local/bin/wallpaper.script &
conky &
/usr/local/bin/battery-level &
notify-send "Started all programmes"
