/*
 * ICU.c
 *
 * Created: 7/24/2020 2:17:40 PM
 * Author : nashwa.hamed
 */ 

#include "Timer.h"
#include "LCD.h"
extern uint32 ICU_ReadCaptureVal_1;
extern uint32 ICU_ReadCaptureVal_2;
extern uint32 ICU_ReadCaptureVal_3;
extern uint8 Cap_Counter;

int main(void)
{
    /* Replace with your application code */
	uint32 duty=0;
	uint32 freq=0;
	LCD_Init();

	PWM2_Init();
	PWM2_Generate(70);

	ICU_Init();
    while (1) 
    {
		if(Cap_Counter ==3){
		duty =((ICU_ReadCaptureVal_2-ICU_ReadCaptureVal_1)*100)/(ICU_ReadCaptureVal_3-ICU_ReadCaptureVal_1);
		freq= (8000000/(ICU_ReadCaptureVal_3-ICU_ReadCaptureVal_1));
		LCD_GoTo(0,0);
		LCD_WriteString("Duty Cycle:");
		LCD_WriteInteger(duty);
		LCD_WriteChar('%');

		LCD_GoTo(1,0);
		LCD_WriteString("Frequency:");
		LCD_WriteInteger(freq);
		LCD_WriteString("HZ");
		Cap_Counter=0;
		SET_BIT(TIMSK,5);


		}

    }
}

