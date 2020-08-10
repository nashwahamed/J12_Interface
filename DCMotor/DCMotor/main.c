/*
 * DCMotor.c
 *
 * Created: 7/24/2020 10:34:29 AM
 * Author : nashwa.hamed
 */ 

#include "DCMotor.h"


int main(void)
{
    /* Replace with your application code */
	DCMotor_Init();
	DCMotor_SetDir(CLOCK_WISE_DIR);
	DCMotor_SetSpeed(10);
	DCMotor_Start();
    while (1) 
    {
    }
}

