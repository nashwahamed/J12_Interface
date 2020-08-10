/*
 * DCMotor.h
 *
 * Created: 7/24/2020 10:36:04 AM
 *  Author: nashwa.hamed
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "DIO.h"
#include "Timer.h"

typedef enum{
CLOCK_WISE_DIR,
ANTI_CLOCK_WISE_DIR
}DC_MOTOR_DIR;

 void DCMotor_Init(void);
 void DCMotor_SetSpeed(uint8 speed);
 void DCMotor_SetDir(DC_MOTOR_DIR dir);
 void DCMotor_Start(void);
 void DCMotor_Stop(void);



#endif /* DCMOTOR_H_ */