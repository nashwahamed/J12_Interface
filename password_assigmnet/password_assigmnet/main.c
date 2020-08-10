/*
 * password_assigmnet.c
 *
 * Created: 8/10/2020 10:03:27 PM
 * Author : nashwa.hamed
 */ 
 #include "LCD.h"
 #include "KeyPad.h"
 #include "Temp_Sensor.h"
#define F_CPU 16000000
#include <util/delay.h>

  /******global for password**********/
  uint8 i=0,match=0,keyValue=0,iteration=0,arrIndex=0;
  uint8 arr[6]={5,4,5,4,5,4};
  uint8 enteredPass[6]={};
  uint16 temp=0;
  void PasswordCheck(void);
  /*********global password end region**********/

int main(void)
{
     /*****************password check variable start***********************/
     TempSensor_Init();
     LCD_Init();
     KeyPad_Init();
     /***********************password check variable end region**********************/
    while (1) 
    {
	 PasswordCheck();
    }
}

void PasswordCheck(){
/*
if(iteration==0){
	LCD_WriteString("Enter Pass");
	_delay_ms(10);
	LCD_Clear();
}*/



keyValue=KeyPad_GetValue();
if(keyValue){
	if(iteration<=6)
		iteration++;
	enteredPass[arrIndex]=keyValue;
	LCD_WriteChar(enteredPass[arrIndex]);
	arrIndex++;

if(iteration==6){
	for(i=0;i<6;i++){
		if(enteredPass[i] == arr[i])
		match=1;
		else{
		match=0;
		break;
		}
	}
}

if(match && iteration>=6){
	LCD_WriteString("Pass match ");
	TempSensor_Read(&temp);
	LCD_Clear();
	LCD_WriteInteger(temp);
	_delay_ms(100);
	}else if(iteration>=6){
	LCD_Clear();
	for(i=0;i<6;i++){
		LCD_WriteChar(enteredPass[i]);
	}
	_delay_ms(100);
	LCD_Clear();
	LCD_WriteString("Pass Incorrect");
	_delay_ms(100);
	LCD_Clear();
	iteration=0;
	arrIndex=0;
	}
	}
}

