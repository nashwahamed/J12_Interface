/*
 * SPI_Slave.c
 *
 * Created: 8/7/2020 12:48:36 PM
 * Author : nashwa.hamed
 */ 

#include "SPI.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	uint8 tx_data=1, rx_data=0;
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_OUTPUT);

	SPI_Slave_Init();
	while (1) 
    {
	rx_data=SPI_TranSiver(tx_data);
	if(rx_data==2){
		DIO_TogglePin(DIO_PORTD,DIO_PIN0);
		rx_data=0;
	}
	_delay_ms(1000);
    }
}

