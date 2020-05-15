#!/bin/bash
house="${HOME}/.config/dwm"
"${house}/dwmstatus" &
compton -i $HOME/.config/compton.conf &
/usr/local/bin/wallpaper.script &
conky &
/usr/local/bin/battery-level &
nmcli c up 3e5e8aa3-b981-496b-9fd2-ec767675d1e8 &
sleep 30 &
/opt/appimages/Nextcloud-2.6.4-x86_64.AppImage &
notify-send "Started all programmes" &
