/*
 * Buzzer.h
 *
 *  Created on: Jul 9, 2020
 *      Author: nashwa.hamed
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO.h"

#define BUZZER_PORT DIO_PORTA
#define BUZZER_PIN DIO_PIN3

void Buzzer_Init(void);
void Buzzer_ring(void);
void Buzzer_Off(void);



#endif /* BUZZER_H_ */
