/*
 * Servo.c
 *
 * Created: 7/24/2020 12:31:18 PM
 *  Author: nashwa.hamed
 */ 
 #include "Servo.h"
 void Servo_Init(void){
 DIO_SetPinDir(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
 PWM1_Init();
 PWM1_Start();
 }
 void Servo_SetDegree(uint8 degree){}