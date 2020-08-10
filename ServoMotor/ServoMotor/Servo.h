/*
 * Servo.h
 *
 * Created: 7/24/2020 12:31:33 PM
 *  Author: nashwa.hamed
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "Timer.h"
#include "DIO.h"

void Servo_Init(void);
//minimum resolution is 12 degree increment by 12
void Servo_SetDegree(uint8 degree);



#endif /* SERVO_H_ */