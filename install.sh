#!/bin/bash

casa="$HOME/.config/dwm/"

[[ -d ${casa} ]] || mkdir "${casa}"
cp autostart.sh dwmstatus lock-fusy.sh poweroff.py "${casa}"
chmod +x "${casa}" -R

echo "Installing dwm, to control backlight and keyboard lights, please make sure to enable the sudo to run the scripts without password for more straight forward workflow"
sleep 5
sudo cp screen-backlight keyboard-backlight /usr/local/bin
sudo chmod +x /usr/local/bin/*backlight 
sudo cp dwm.desktop /usr/share/xsessions/
sudo make
sudo make clean install
sleep 5

clear
echo "Add these lines to your sudoers file, replace user to your user or group
user ALL= (root) NOPASSWD: /usr/local/bin/screen-backlight
user ALL= (root) NOPASSWD: /usr/local/bin/keyboard-backlight"
echo "Also make sure that the path exist for these files"
echo "/sys/class/backlight/*/brightness The * is the driver for your screen hardware"
echo "/sys/class/leds/smc::kdb_backlight/brightness is the file for your keyboard"
echo "If these files does not exist than ignore these instructions"

