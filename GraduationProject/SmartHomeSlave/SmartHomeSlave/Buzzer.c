/*
 * Buzzer.c
 *
 *  Created on: Jul 9, 2020
 *      Author: nashwa.hamed
 */
#include "Buzzer.h"

void Buzzer_Init(){
	DIO_SetPinDir(BUZZER_PORT,BUZZER_PIN,DIO_PIN_OUTPUT);
}
void Buzzer_ring(){
	DIO_WritePin(BUZZER_PORT,BUZZER_PIN,DIO_PIN_HIGH);
}
void Buzzer_Off(){
	DIO_WritePin(BUZZER_PORT,BUZZER_PIN,DIO_PIN_LOW);
}

