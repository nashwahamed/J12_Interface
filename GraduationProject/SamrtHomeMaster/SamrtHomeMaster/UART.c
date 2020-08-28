/*
 * UART.c
 *
 * Created: 7/25/2020 12:50:53 PM
 *  Author: nashwa.hamed
 */ 
 #include "UART.h"

 void UART_Init(void){
 uint32 BR_Value=0;

 DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
 DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

 UCSRB |= 0x18;//no interrup enabled only trX Rrx

 UCSRC |= 0x86 ;//8 bit use as ucsr

 //equation boadrate Fosc/(BR*16)-1 =((16000000)/(9600 * 16))-1;

 BR_Value=((40000)/(96 * 8))-1;//((160000)/(96 * 16))-1;//103.16
 UBRRL = BR_Value;

 }
 void UART_SendByte(uint8 data){
 //polling on the flag
 while(GET_BIT(UCSRA,5)==0);

 UDR =data;
 }
 uint8 UART_ReceiveByte(void){
	uint8 data=0;
	while(GET_BIT(UCSRA,7)==0);
	data=UDR;
	return data;
 }

 void UART_SendString(uint8* str){
	uint8 i =0;
	while(str[i] != '\0'){
		UART_SendByte(str[i]);
		i++;
	}
 }
 uint8 UART_ReceiveString(void){
 return 0;
 }