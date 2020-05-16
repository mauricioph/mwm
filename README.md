# Mauricio's dwm
My DWM setup nothing fancy. I just wanted to know how to work with DWM, most of my costumisation is based on my setup on i3.

Theme:
| Colour | HTML Code |
|--------|-----------|
| gray1  | #222222 |
| gray2  | #444444 |
| gray3  | #bbbbbb |
| gray4  | #eeeeee |
| cyan   | #005577 |

These are the features:

| Keybind |  Command |
|---------|----------|
| Super + g | VScode |
| Super + e | power off script |
| Super + f | Firefox |
| Super + t | lockscreen |
| Super + d | rofi menu |
| Super + r | Fibonacci layout |
| Super + n | Connect to the wifi |
| Super + b | Toggle the bar |
| Super + j | Switch Focus Stack |
| Super + k | Switch Focus Stack |
| Super + i | Switch Layout |
| Super + h | Decrease Master Area |
| Super + l | Increase Master Area |
| Super + t | Toggle Layout to Vertical Master/Stack|
| Super + f | Toggle Layout to Vertical Master/Stack|
| Super + r | Toggle Layout to Fullscreen |
| Super + Tab | switch tabs |
| Super + Enter | st Terminal |
| Super + minus | Descrease gaps |
| Super + equal | Increase gaps |
| Super + Shift + equal | Set gaps to 0
| Super + Shift + Enter | Swap Master with Stack window |
| Super + Shift + Space | Toggle Floating |
| Super + Shift + r | dwindle decrese the space for the stack making the master bigger. |
| Super + Shift + e | exit dwm |
| Super + Shift + q | Quit the programs |
| Super + Shift + a | Ocenaudio Audio editor |
| Super + Shift + v | VLC |
| Super + Shift + t | Lockscreen script |
| XF86 AudioRaiseVolume | pactl set-sink-volume 0 +5% |
| XF86 AudioLowerVolume | pactl set-sink-volume 0 -5% |
| XF86 AudioMute | pactl set-sink-volume 0 0 |
| XF86 MonBrightnessUp | script screen-backlight up |
| XF86 MonBrightnessDown | script screen-backlight down |
| XF86 KbdBrightnessUp | script keyboard-backlight total |
| XF86 KbdBrightnessDown | script keyboard-backlight off |


##Install:
```
git clone https://github.com/mauricioph/dwm.git
cd dwm
chmod +x install.sh
./install.sh

# visudo in some distro will allow you to change the sudoers file
visudo

# add the following replacing the user with your username or group

user ALL= (root) NOPASSWD: /usr/local/bin/screen-backlight
user ALL= (root) NOPASSWD: /usr/local/bin/keyboard-backlight

