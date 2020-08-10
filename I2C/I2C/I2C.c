/*
 * I2C.c
 *
 * Created: 8/8/2020 12:40:40 PM
 *  Author: nashwa.hamed
 */ 
 #include "I2C.h"

 void I2C_Init_Master(void){
 //generated clk =Fcpu/(16+(2*TWBR*(4^TWPS)))
 //need 400KHZ as generated clock so TWPS=0 TWBR=12
 TWBR = 0x0c;
 CLR_BIT(TWSR,0);
 CLR_BIT(TWSR,1);

 //enable I2C
 SET_BIT(TWCR,2);
 //clear flag
 }
 void I2C_Init_Slave(void){
 TWAR =(0x01 << 1);//device address 
 //enable
 SET_BIT(TWCR,2);

 }
 void I2C_Star_Cond(void){

 SET_BIT(TWCR,5);
 //for each operation enable again I2C
 SET_BIT(TWCR,2); 
 //clear flag in AVR by writing 1 only in AVR --by hardware
 SET_BIT(TWCR,7);

 //stop till flag done polling
 while(GET_BIT(TWCR,7)==0);

 while((TWSR & 0xF8) == START_COND);

 }
 void I2C_Repeated_Start(void){
  SET_BIT(TWCR,5);
  //for each operation enable again I2C
  SET_BIT(TWCR,2);
  //clear flag in AVR by writing 1 only in AVR --by hardware
  SET_BIT(TWCR,7);

  //stop till flag done polling
  while(GET_BIT(TWCR,7)==0);

  while((TWSR & 0xF8) == REPEATE_START_COND);
 }
 void I2C_Send_Slave_Address_Write_Operation(uint8 addr){
 //only shift left as by default MSB will be zero which is write opr
 TWDR = (addr << 1);
  //for each operation enable again I2C
  SET_BIT(TWCR,2);
  //clear flag in AVR by writing 1 only in AVR --by hardware
  SET_BIT(TWCR,7);
   while(GET_BIT(TWCR,7)==0);

   while((TWSR & 0xF8) == SLAV_ADD_WRITE_ACK_RECEIVED);

 }
 void I2C_Send_Slave_Address_Read_Operation(uint8 addr){
 TWDR = (addr << 1) | 0x01;

   //for each operation enable again I2C
   SET_BIT(TWCR,2);
   //clear flag in AVR by writing 1 only in AVR --by hardware
   SET_BIT(TWCR,7);
   while(GET_BIT(TWCR,7)==0);

   while((TWSR & 0xF8) == SLAV_ADD_Read_ACK_RECEIVED);
 }
 void I2C_Write_Byte(uint8 data){
 TWDR = data;
 //for each operation enable again I2C
 SET_BIT(TWCR,2);
 //clear flag in AVR by writing 1 only in AVR --by hardware
 SET_BIT(TWCR,7);
 while(GET_BIT(TWCR,7)==0);

 while((TWSR & 0xF8) == 0x28);
 }
 uint8 I2C_Read_Byte(void){
 SET_BIT(TWCR,2);
 //clear flag in AVR by writing 1 only in AVR --by hardware
 SET_BIT(TWCR,7);
 while(GET_BIT(TWCR,7)==0);

 while((TWSR & 0xF8) == 0x58);

 return TWDR;
 }
 void I2C_Stop(void){
 SET_BIT(TWCR,4);
 //for each operation enable again I2C
 SET_BIT(TWCR,2);
 //clear flag in AVR by writing 1 only in AVR --by hardware
 SET_BIT(TWCR,7);

 //stop till flag done polling
 while(GET_BIT(TWCR,7)==0);
//no status for stop
 }