// modified code to work with generic mouse, as USB Mouse Passthrough
// modifed to work with generic USB 2.0 mouse: working mouse x and y positions, right click, left click, middle mouse click,
// also mouse scrollwheel all works (tested on generic usb mouse: "HP Wired mouse 1000")
//
// based of code from: https://github.com/mustaffxx/usb-host-shield-mouse
// modifed by Id-ware: https://github.com/Id-ware/usb-host-shield-mouse

#include <Mouse.h>
#include <hiduniversal.h>
#include "hidmouserptparser.h"

USB Usb;
HIDUniversal Hid(&Usb);
HIDMouseReportParser Mou(nullptr);

bool Serialout = false;  // serial output switch (for displaying debugging information in serial monitor)

void setup() {
  Mouse.begin();
  if (Serialout == true) {
    Serial.begin(115200);
    Serial.println("Start");
  }
    if (Usb.Init() == -1)
      if (Serialout == true) {Serial.println("OSC did not start.");}
  delay(200);
  

  if (!Hid.SetReportParser(0, &Mou))
    ErrorMessage<uint8_t >(PSTR("SetReportParser"), 1);
}

void loop() {
  Usb.Task();
}

void onButtonDown(uint16_t buttonId) {
  Mouse.press(buttonId);

  if (Serialout == true) {
    Serial.print("Button ");
    switch (buttonId) {
      case MOUSE_LEFT:
        Serial.print("MOUSE_LEFT");
        break;

      case MOUSE_RIGHT:
        Serial.print("MOUSE_RIGHT");
        break;

      case MOUSE_MIDDLE:
        Serial.print("MOUSE_MIDDLE");
        break;

      default:
        Serial.print("OTHER_BUTTON");
        break;
    }
    Serial.println(" pressed");
  }
}

void onButtonUp(uint16_t buttonId) {
  Mouse.release(buttonId);

  if (Serialout == true) {
    Serial.print("Button ");
    switch (buttonId) {
      case MOUSE_LEFT:
        Serial.print("MOUSE_LEFT");
        break;

      case MOUSE_RIGHT:
        Serial.print("MOUSE_RIGHT");
        break;

      case MOUSE_MIDDLE:
        Serial.print("MOUSE_MIDDLE");
        break;

      default:
        Serial.print("OTHER_BUTTON");
        break;
    }
    Serial.println(" released");
  }
}

void onMouseMove(int8_t xMovement, int8_t yMovement, int8_t scrollValue) {
  Mouse.move(xMovement, yMovement, scrollValue);

  if (Serialout == true) {
    Serial.print("Mouse moved:\t");
    Serial.print(xMovement);
    Serial.print("\t");
    Serial.print(yMovement);
    Serial.print("\t");
    Serial.println(scrollValue);
  }
}
