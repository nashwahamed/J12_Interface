/*
 * SmartHomeSlave.c
 *
 * Created: 8/23/2020 1:01:54 AM
 * Author : nashwa.hamed
 */ 

#include "SPI.h"
#include "LED.h"
#include "DCMotor.h"
#define F_CPU 4000000
#include <util/delay.h>


int main(void)
{
    uint8 tx_data=3, rx_data=0;
	
	SPI_Slave_Init();
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DCMotor_Init();
	LED0_Init();

	//LED0_ON();
	DCMotor_SetDir(CLOCK_WISE_DIR);
	DCMotor_SetSpeed(10);
	DCMotor_Start();
	
    while (1) 
    {
		rx_data=SPI_TranSiver(tx_data);
		if(rx_data=='l'){
			LED0_Toggle();
			rx_data=0;
		}
		if(rx_data=='c'){
			DCMotor_Stop();
			DCMotor_SetDir(CLOCK_WISE_DIR);
			DCMotor_SetSpeed(10);
			DCMotor_Start();
			rx_data=0;
		}
		if(rx_data=='a'){
			DCMotor_Stop();
			DCMotor_SetDir(ANTI_CLOCK_WISE_DIR);
			DCMotor_SetSpeed(10);
			DCMotor_Start();
			rx_data=0;
		}
		_delay_ms(500);
    }
}

