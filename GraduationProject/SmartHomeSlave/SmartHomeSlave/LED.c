#include "LED.h"


void LED0_ON(void){
	//SET_BIT(PORTC,2);
	DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
}
void LED0_OFF(void){
	//clear_Bit(PORTC,2);
	DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
}
void LED0_Init(void){
	//SET_BIT(DDRC,2);
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
}
void LED0_Toggle(void){
	//toggle_Bit(PORTC,2);
	DIO_TogglePin(DIO_PORTC,DIO_PIN2);
}