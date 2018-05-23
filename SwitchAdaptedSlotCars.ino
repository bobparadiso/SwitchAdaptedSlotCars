#include <Wire.h>
#include "SlotCar.h"

#define MOTOR1_PIN 9
#define MOTOR2_PIN 10
#define BTN1_PIN A0
#define BTN2_PIN A1

SlotCar car1(MOTOR1_PIN, BTN1_PIN);
SlotCar car2(MOTOR2_PIN, BTN2_PIN);

//
void setup()
{
	Serial.begin(115200);

	//set PWM frequency divisor
	TCCR1B = TCCR1B & 0b11111000 | 0x01;
	
	car1.init();
	car2.init();
	
	while (1)
	{
		car1.update();
		car2.update();
	}
}

//
void loop() {}

