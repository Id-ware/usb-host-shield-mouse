// modified code to work with generic mouse, as USB Mouse Passthrough
// modifed to work with generic USB 2.0 mouse: working mouse x and y positions, right click, left click, middle mouse click, 
// also mouse scrollwheel all works (tested on generic usb mouse: "HP Wired mouse 1000")
//
// based of code from: https://github.com/mustaffxx/usb-host-shield-mouse
// modifed by Id-ware: https://github.com/Id-ware/usb-host-shield-mouse

#if !defined(__HIDMOUSERPTPARSER_H__)

#define __HIDMOUSERPTPARSER_H__

#include <usbhid.h>

#define MOUSE_LEFT 		1
#define MOUSE_RIGHT 	2
#define MOUSE_MIDDLE 	4


void onButtonUp(uint16_t buttonId) __attribute__((weak));
void onButtonDown(uint16_t buttonId) __attribute__((weak));
void onMouseMove(int8_t xMovement, int8_t yMovement, int8_t scrollValue) __attribute__((weak));


class HIDMouseReportParser : public HIDReportParser {
	uint8_t previousButtonsState;
public:
	HIDMouseReportParser(void *);
	virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};

#endif//__HIDMOUSERPTPARSER_H__
