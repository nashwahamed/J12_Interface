


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#include "STD.h"

#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*((volatile uint8*)(0x35)))
#define PINC  (*((volatile uint8*)(0x33)))
#define DDRC  (*((volatile uint8*)(0x34)))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))

/**************Status Register(Interupt)***********************/
#define SREG (*(volatile uint8*)(0x5F))
#define GICR (*(volatile uint8*)(0x5B))
#define GIFR (*(volatile uint8*)(0x5A))
#define MCUCR (*(volatile uint8*)(0x55))
#define MCUCSR (*(volatile uint8*)(0x54))

/*****************ADC**************/
#define ADMUX		(*(volatile uint8*)(0x27))
#define ADCSRA		(*(volatile uint8*)(0x26))
#define ADCH		(*(volatile uint8*)(0x25))
#define ADCL		(*(volatile uint8*)(0x24))
#define ADC_Adjust (*(volatile uint16*)(0x24))
#define SFIOR		(*(volatile uint8*)(0x50))

/***************Timer****************/
#define TCCR0		(*(volatile uint8*)(0x53))
#define TCNT0		(*(volatile uint8*)(0x52))
#define OCR0		(*(volatile uint8*)(0x5C))
#define TIMSK		(*(volatile uint8*)(0x59))
#define TIFR		(*(volatile uint8*)(0x58))

#define TCCR1A		(*(volatile uint8*)(0x4F))
#define TCCR1B		(*(volatile uint8*)(0x4E))
#define TCNT1L		(*(volatile uint16*)(0x4C))
#define OCR1AL		(*(volatile uint16*)(0x4A))
#define ICR1		(*(volatile uint16*)(0x46))

/*********************** Timer2 *********************/
#define TCCR2		(*(volatile uint8*)(0x45))
#define OCR2		(*(volatile uint8*)(0x43))

/********************** UART ****************/
#define UDR			(*(volatile uint8*)(0x2C))
#define UBRRL		(*(volatile uint8*)(0x29))
#define UCSRA		(*(volatile uint8*)(0x2B))
#define UCSRB		(*(volatile uint8*)(0x2A))
#define UCSRC		(*(volatile uint8*)(0x40))

/********************* SPI *******************/
typedef struct{
uint8 SPCR;
uint8 SPSR;
uint8 SPDR;

}SPI_REGS;
#define SPI		((volatile SPI_REGS*)(0x2D))

/*************************** I2C ****************/
#define TWCR		(*(volatile uint8*)(0x56))
#define TWDR		(*(volatile uint8*)(0x23))
#define TWAR		(*(volatile uint8*)(0x22))
#define TWBR		(*(volatile uint8*)(0x20))
#define TWSR		(*(volatile uint8*)(0x21))

#endif /* ATMEGA32_REG_H_ */