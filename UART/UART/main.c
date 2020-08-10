/*
 * UART.c
 *
 * Created: 7/25/2020 11:59:23 AM
 * Author : nashwa.hamed
 */ 

#include "UART.h"
#include "LCD.h"
#define  F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	UART_Init();
	LCD_Init();
	//UART_SendString("Nashwa");
	UART_SendByte('N');
	uint8 rx=0;
    /* Replace with your application code */
    while (1) 
    {
	rx= UART_ReceiveByte();
	_delay_ms(100);
	LCD_WriteChar(rx);
	
    }
}

