/*
 * SPI.h
 *
 * Created: 8/7/2020 12:11:49 PM
 *  Author: nashwa.hamed
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "DIO.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
//intiate transmition
void SPI_Master_InitTrans(void);
//terminate transimition
void SPI_Master_TerTrans(void);
//transmite and receive
uint8 SPI_TranSiver(uint8);

#endif /* SPI_H_ */