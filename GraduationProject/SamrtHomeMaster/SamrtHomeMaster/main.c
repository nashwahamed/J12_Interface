/*
 * SamrtHomeMaster.c
 *
 * Created: 8/23/2020 12:26:26 AM
 * Author : nashwa.hamed
 */ 

#include "UART.h"
#include "SPI.h"
#define  F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	UART_Init();
    uint8 tx_data=0, rx_data=0;
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
    while (1) 
    {
		UART_SendString("Press l to On/Off Led or b to On/Off Buzzer");
		tx_data=UART_ReceiveByte();
		rx_data=SPI_TranSiver(tx_data);
		if(rx_data==2){
			DIO_TogglePin(DIO_PORTC,DIO_PIN2);
			rx_data=0;
		}
		_delay_ms(500);
    }
}

