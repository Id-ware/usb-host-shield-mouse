# usb-host-shield-mouse
This project is an example of using a [USB HOST SHIELD 2.0](https://github.com/felis/USB_Host_Shield_2.0) to interface with a Generic USB 2.0 mouse and Pass it through (via arduino leonardo) to the computer as an HID mouse.
```
[USB Mouse] --> [USB Host Shield 2.0] --> [Arduino Leonardo] --FAKE HID USB--> [Computer]
```
i modified the code to make it work with a generic mouse.
here is a list of stuff that i tested and worked:
- x and y mouse position (not absolute)
- right click, left click, middle mouse click
- mouse scrollwheel finally works

--
based of code from: https://github.com/mustaffxx/usb-host-shield-mouse
modifed by Id-ware: https://github.com/Id-ware/usb-host-shield-mouse


# Hardware Requirements
- Arduino Leonardo
- USB Host Shield 2.0
- generic USB 2.0 mouse (i tested it with "HP Wired mouse 1000"

# How to Use
1.  Connect the USB Host Shield to the Arduino Leonardo.
2.  Connect the Generic USB 2.0 Mouse to the USB Host Shield.
3.  Upload the "hidmousereport.ino" sketch to the Arduino Leonardo.
4. wait for the code to completely uploaded and finish, and if everything went well it should work, you should be able to use the mouse on your pc.

# Optional steps (for debugging):
6.  Open the Arduino Serial Monitor and select a baud rate of 115200.
7.  Move the mouse around and click the buttons to see the output on the Serial Monitor.

# troubleshooting
- make sure you use the latest version of arduino ide (the one i used is: Arduino IDE version 2.1.0 (CLI version 0.32.2))
- make sure you using mouse library version 1.0.1 (thats what <Mouse.h> uses)
- make sure you using usb host shield library 2.0 version 1.6.2 (thats what <hiduniversal.h> uses iirc)
- make sure you selected the right board and port from the arduino ide software
- make sure "hidmousereport.ino" is in the same folder with "hidmouserptparser.cpp" and "hidmouserptparser.h"

# afterthought
i made this version because i want to try in the future to reroute the mouse buttons to do different actions
but that will be in another git-repo and a work in progress...
