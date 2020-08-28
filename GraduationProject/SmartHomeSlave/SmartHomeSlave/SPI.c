/*
 * SPI.c
 *
 * Created: 8/7/2020 12:13:18 PM
 *  Author: nashwa.hamed
 */ 
 #include "SPI.h"


 void SPI_Master_Init(void){

 DIO_SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
 DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
 DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);//MISO
 DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);

 SPI->SPCR=0x53;
 }
 void SPI_Slave_Init(void){

 DIO_SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);
 DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
 DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);//MISO
 DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);

  SPI->SPCR=0x43;//only enable interrupt

 }
 //intiate transmition
 void SPI_Master_InitTrans(void){
 DIO_WritePin(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
 }
 //terminate transimition
 void SPI_Master_TerTrans(void){
  DIO_WritePin(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
 }
 //transmite and receive
 uint8 SPI_TranSiver(uint8 trans_data){
 uint8 rec_data=0;
 SPI ->SPDR=trans_data;//data need to be send
 /*if(GET_BIT(SPI->SPSR,6)){
	 _delay_ms(100);
	 SPI ->SPDR=trans_data;//in case write collision try to retransmite
 }*/

 while(GET_BIT(SPI->SPSR,7)==0);//once 1 means transmite done

 rec_data=SPI->SPDR;
 return rec_data;
 }