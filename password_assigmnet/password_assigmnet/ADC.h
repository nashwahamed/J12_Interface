/*
 * ADC.h
 *
 * Created: 09/07/2020 04:49:28 م
 *  Author: Ali
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"
#include "ADC_Cfg.h"

#define  ADC_VREF_AVCC         0

#define  ADC_RIGHT_ADJUST      1

#define  ADC_CHANNEL_1         1

#define  ADC_AUTO_TRIGGER      0

#define  ADC_PRESC_128         0

#define  ADC_INTERRUPT_ENABLE   0

#define  ADC_INTERRUPT_DISABLE  1


/**********************************  APIs  **************************************/


void ADC_Init(void);

void ADC_Read(uint16* value);


#endif /* ADC_H_ */