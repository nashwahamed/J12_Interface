/*
 * ServoMotor.c
 *
 * Created: 7/24/2020 12:30:24 PM
 * Author : nashwa.hamed
 */ 

#include "Servo.h"


int main(void)
{
	Servo_Init();
	PWM1_Generate(7);
    /* Replace with your application code */
    while (1) 
    {
    }
}

