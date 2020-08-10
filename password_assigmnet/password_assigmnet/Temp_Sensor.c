/*
 * CFile1.c
 *
 * Created: 11/07/2020 06:46:35 ص
 *  Author: Ali
 */ 


#include "Temp_Sensor.h"



void TempSensor_Init(void)
{
	
	ADC_Init();
	
}

void TempSensor_Read(uint16* Temp)
{
	
	//uint16 Analog_Value = 0;
	
	ADC_Read(Temp); 
	
//	*Temp = Analog_Value * 10 ;
	
}
