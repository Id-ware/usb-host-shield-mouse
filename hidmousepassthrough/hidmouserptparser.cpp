// modified code to work with generic mouse, as USB Mouse Passthrough
// modifed to work with generic USB 2.0 mouse: working mouse x and y positions, right click, left click, middle mouse click, 
// also mouse scrollwheel all works (tested on generic usb mouse: "HP Wired mouse 1000")
//
// based of code from: https://github.com/mustaffxx/usb-host-shield-mouse
// modifed by Id-ware: https://github.com/Id-ware/usb-host-shield-mouse

#include "hidmouserptparser.h"


HIDMouseReportParser::HIDMouseReportParser(void *) : previousButtonsState(0) {};

void HIDMouseReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) { 
	for (uint16_t buttonId = 1; buttonId <= 16; buttonId <<= 1) {
		if (buf[0] & buttonId) {
			if (!(previousButtonsState & buttonId)) {
				onButtonDown(buttonId);
			}
		} else {
			if (previousButtonsState & buttonId) {
				onButtonUp(buttonId);
			}
		}
	}
	previousButtonsState = buf[0];

	int8_t xMovement = buf[1];
	int8_t yMovement = buf[2];
	int8_t scrollValue = buf[3];

	if (xMovement > 127) xMovement -= 256;
	if (yMovement > 127) yMovement -= 256;

	if (xMovement != 0 || yMovement != 0 || scrollValue != 0)
		onMouseMove(xMovement, yMovement, scrollValue);

}
