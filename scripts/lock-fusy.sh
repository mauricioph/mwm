#!/bin/sh -e

# mwm folder
mwmfolder="$HOME/.config/mwm"
# Icon
icon="${mwmfolder}/icon.png"
# Take a screenshot
locker=$(mktemp /tmp/.lock.XXXXX.png)
locked=$(basename ${locker})
scrot ${mwmfolder}/${locked}

if [ -f ${mwmfolder}/screen_locked.png ]
then rm -f ${mwmfolder}/screen_locked.png
fi

# Pixellate it 10x and write the enter the password phrase.
convert -resize 10% ${mwmfolder}/${locked} ${mwmfolder}/screen_locked2.png
convert -resize 1000% ${mwmfolder}/screen_locked2.png ${mwmfolder}/screen_locked3.png
rm ${mwmfolder}/screen_locked2.png
convert ${mwmfolder}/screen_locked3.png  "$icon" -gravity center -composite -font Helvetica -pointsize 32 -draw "gravity South fill black text 3,14 'Enter ${USER} password' fill blue  text 1,14 'Enter ${USER} password'" ${mwmfolder}/screen_locked.png

rm ${mwmfolder}/screen_locked3.png
rm ${mwmfolder}/${locked}
rm ${locker}
# Lock screen displaying this image.
i3lock -i ${mwmfolder}/screen_locked.png

# Turn the screen off after a delay.
sleep 300; pgrep mwmlock && xset dpms force off
