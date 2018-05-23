#include "SlotCar.h"

#define CAR_FADE_DURATION 3000
#define CAR_START_SPEED_DURATION 50
#define CAR_SPEED_START 255
#define CAR_SPEED_FADE_START 150
#define CAR_SPEED_FADE_END 60
 
//
SlotCar::SlotCar(uint8_t _motorPin, uint8_t _btnPin): motorPin(_motorPin), btnPin(_btnPin), motorPower(0)
{
}

//
void SlotCar::init()
{
	pinMode(motorPin, OUTPUT);
	pinMode(btnPin, INPUT_PULLUP);
}

//
void SlotCar::update()
{
	uint8_t btnPressed = digitalRead(btnPin) == LOW;

	if (btnPressed)
	{
		if (!motorPower)
			carStartTime = millis();
		
		motorPower = 1;
		btnTime = millis();
	}
	
	if (motorPower)
	{
		uint32_t fadeElapsed = millis() - btnTime;

		if (!btnPressed && fadeElapsed >= CAR_FADE_DURATION)
		{
			analogWrite(motorPin, 0);
			motorPower = 0;
		}
		else
		{
			uint32_t carElapsed = millis() - carStartTime;
			if (carElapsed < CAR_START_SPEED_DURATION)
				analogWrite(motorPin, CAR_SPEED_START);
			else
				analogWrite(motorPin, map(fadeElapsed, 0, CAR_FADE_DURATION, CAR_SPEED_FADE_START, CAR_SPEED_FADE_END));
		}
	}
}
