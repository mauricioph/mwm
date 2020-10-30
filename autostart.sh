#!/bin/bash
house="${HOME}/.config/dwm"
"${house}/scripts/ligamento" &
compton -i $HOME/.config/compton.conf &
/usr/local/bin/wallpaper.script &
conky &
/usr/local/bin/battery-level &
play /usr/share/sounds/Ps1\ startup\ sound.flac &
#nmcli c up 3e5e8aa3-b981-496b-9fd2-ec767675d1e8 &
sleep 30 &
/opt/appimages/Nextcloud-3.0.1-x86_64.AppImage &
notify-send "Started all programmes" &
xautolock -time 5 -locker "/home/mauricio/.config/dwm/lock-fusy.sh" -secure -detectsleep &
