/*
 * I2C.h
 *
 * Created: 8/8/2020 12:40:56 PM
 *  Author: nashwa.hamed
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"
#include "DIO.h"

#define START_COND							0x08
#define REPEATE_START_COND					0x10
#define SLAV_ADD_WRITE_ACK_RECEIVED			0X18
#define SLAV_ADD_WRITE_NOT_ACK_RECEIVED					0x20
#define SLAV_ADD_Read_ACK_RECEIVED					0x28
#define SLAV_ADD_Read_NOT_ACK_RECEIVED				0x30

void I2C_Init_Master(void);
void I2C_Init_Slave(void);
void I2C_Star_Cond(void);
void I2C_Repeated_Start(void);
void I2C_Send_Slave_Address_Write_Operation(uint8 addr);
void I2C_Send_Slave_Address_Read_Operation(uint8 addr);
void I2C_Write_Byte(uint8 data);
uint8 I2C_Read_Byte(void);
void I2C_Stop(void);

//eeprom write eeprom read

#endif /* I2C_H_ */