/*
 * DCMotor.c
 *
 * Created: 7/24/2020 10:35:47 AM
 *  Author: nashwa.hamed
 */ 
 #include "DCMotor.h"

void DCMotor_Init(void){
DIO_SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
DIO_SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
DIO_SetPinDir(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

PWM0_Init();

}
void DCMotor_SetSpeed(uint8 speed){
speed *=10;
PWM0_Generate(speed);
}
void DCMotor_SetDir(DC_MOTOR_DIR dir){
switch(dir){
case CLOCK_WISE_DIR:
DIO_WritePin(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
DIO_WritePin(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
break;

case ANTI_CLOCK_WISE_DIR:
DIO_WritePin(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
DIO_WritePin(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
break;

default:
break;
}
}
void DCMotor_Start(void){
PWM0_Start();
}
void DCMotor_Stop(void){
DIO_WritePin(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
DIO_WritePin(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
}
