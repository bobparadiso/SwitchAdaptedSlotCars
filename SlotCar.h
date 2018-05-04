#ifndef __SLOTCAR_H_
#define __SLOTCAR_H_

#include <Adafruit_MotorShield.h>

class SlotCar
{
public:
	SlotCar(uint8_t _motorPin, uint8_t _btnPin);
	void init();
	void update();
	
private:
	uint8_t motorPin;
	uint8_t btnPin;
	uint32_t btnTime;
	uint32_t carStartTime;
	uint8_t motorPower;
};

#endif