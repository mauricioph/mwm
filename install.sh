#!/bin/bash

casa="$HOME/.config/dwm/"

[[ -d ${casa} ]] || mkdir "${casa}"
cp autostart.sh dwmstatus poweroff.py "${casa}"
chmod +x "${casa}" -R

echo "Installing dwm, to control backlight and keyboard lights, please make sure to enable the sudo to run the scripts without password for more straight forward workflow"
sleep 5
sudo cp screen-backlight keyboard-backlight /usr/local/bin
sudo cp dwm.desktop /usr/share/xsessions/
sudo make
sudo make clean install
sleep 5

clear
echo "Add these lines to your sudoers file, replace user to your user or group
user ALL= (root) NOPASSWD: /usr/local/bin/screen-backlight
user ALL= (root) NOPASSWD: /usr/local/bin/keyboard-backlight"
