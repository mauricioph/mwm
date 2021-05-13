#!/bin/bash

casa="$HOME/.config/mwm/"

[[ ! -d ${casa} ]] || mkdir "${casa}"
cp -rf scripts/ "${casa}"
chmod +x "${casa}scripts/"

[[ ! -d ${HOME}/Applications ]] && mkdir -p ${HOME}/Applications
export PATH=$PATH:$HOME/Applications/

for i in ${casa}scripts/*
do ln -s ${i} $HOME/Applications/
done

echo -e "Installing mwm, to control backlight and keyboard lights. \nPlease make sure to enable the sudo to run the scripts without password for more straight forward workflow. \nIf your user ${USER} does not have access to sudo please ask an admin to make and install the mwm."
sleep 5
# sudo cp scripts/usb-mounter scripts/screen-backlight scripts/keyboard-backlight /usr/local/bin
# sudo chmod +x /usr/local/bin/*backlight
# sudo chmod +x /usr/local/bin/usb-mounter
sudo cp mwm.desktop /usr/share/xsessions/
sudo make
sudo make clean install
sleep 5

clear
echo -e "Add these lines to your sudoers file, replace user to your user or group. \n $USER ALL= (root) NOPASSWD: /usr/local/bin/screen-backlight \n $USER ALL= (root) NOPASSWD: /usr/local/bin/keyboard-backlight \n $USER ALL= (root) NOPASSWD: /usr/local/bin/usb-mounter \n" 
echo "Also make sure that the path exist for these files"

for i in /sys/class/backlight/*;do [ -f "${i}/brightness" ] && echo "${i}/brightness The * is the driver for your screen hardware";done
for i in /sys/class/leds/*;do a=$(echo "${i}" | awk '/kbd/ {print $1}');[ -f "${a}/brightness" ] && echo "${i}/brightness is your keyboard brightness.";done


