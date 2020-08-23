/*
 * SmartHomeSlave.c
 *
 * Created: 8/23/2020 1:01:54 AM
 * Author : nashwa.hamed
 */ 

#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
    uint8 tx_data=2, rx_data=0;
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	SPI_Slave_Init();
    while (1) 
    {
		rx_data=SPI_TranSiver(tx_data);
		if(rx_data==5){
			DIO_TogglePin(DIO_PORTC,DIO_PIN2);
			rx_data=0;
		}
		if(rx_data==6){
			DIO_TogglePin(DIO_PORTC,DIO_PIN3);
			rx_data=0;
		}
		_delay_ms(500);
    }
}

