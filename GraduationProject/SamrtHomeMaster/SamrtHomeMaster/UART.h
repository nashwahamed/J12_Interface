/*
 * UART.h
 *
 * Created: 7/25/2020 12:51:10 PM
 *  Author: nashwa.hamed
 */ 


#ifndef UART_H_
#define UART_H_
#include "UART_Cfg.h"
#include "DIO.h"

void UART_Init(void);
void UART_SendByte(uint8);
uint8 UART_ReceiveByte(void);

void UART_SendString(uint8* str);
uint8 UART_ReceiveString(void);


#endif /* UART_H_ */