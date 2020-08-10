/*
 * Timer.h
 *
 * Created: 7/17/2020 12:28:57 PM
 *  Author: nashwa.hamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"

void Timer_Init(void);
void Timer_Start(void);
void Timer_Stop(void);
void Timer_Generate_Delay(uint8 delay_ms);
void Timer0_SetCallBack(void (*p)(void));


void Timer1_Init(void);
void Timer1_Start(void);
void Timer1_Stop(void);
void Timer1_Generate_Delay(uint32 delay_ms);
void Timer1_SetCallBack(void (*p)(void));

void PWM0_Init();
//will use current stable value for frequency as it needed a lot of calculation
//normal parameter is frequency and Duty cycle
//freq=16M/(64*256)=Fosclator/(prescaller)*256 =974KHZ
void PWM0_Generate(uint16 DutyCycle);
void PWM0_Start(void);

void PWM1_Init(void);
void PWM1_Generate(uint16 DutyCycle);
void PWM1_Start(void);

void ICU_Init(void);

void PWM2_Init(void);
void PWM2_Generate(uint32 duty_cycle);

#endif /* TIMER_H_ */