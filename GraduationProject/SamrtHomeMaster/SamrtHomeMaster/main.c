/*
 * SamrtHomeMaster.c
 *
 * Created: 8/23/2020 12:26:26 AM
 * Author : nashwa.hamed
 */ 

#include "UART.h"
#include "SPI.h"
#define  F_CPU 4000000
#include <util/delay.h>

int main(void)
{
	UART_Init();
    uint8 tx_data=0, rx_data=0;
	SPI_Master_Init();
	SPI_Master_InitTrans();
    while (1) 
    {
		UART_SendString("Press l to On/Off Led c to clockwise motor a to anticlockwise motor");
		tx_data=UART_ReceiveByte();
		rx_data=SPI_TranSiver(tx_data);
		
    }
}

