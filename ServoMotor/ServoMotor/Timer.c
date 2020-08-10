/*
 * Timer.c
 *
 * Created: 7/17/2020 12:28:45 PM
 *  Author: nashwa.hamed
 */ 
 #include "Timer.h"
 #include <avr/interrupt.h>

  uint16 Num_OverFlow=0;
  uint16 Init_Value=0;
  uint16 Num_Tick=0;
  uint32 Compare_Match=0;
 static void(*pp)(void);
  static void(*timer1_ptr)(void);
 void Timer_Init(void){
 /********Normal Mode********/
 //CLR_BIT(TCCR0,3);
 //CLR_BIT(TCCR0,6);
TCCR0 |= 0x00;
//CTC
TCCR0 |=0x08;

 //overflow interrupt
 //SET_BIT(TIMSK,0);
 TIMSK |= 0x01;

 //TIMSK to CTC
  TIMSK |= 0x02;

 //SET_BIT(SREG,7);
 SREG|=0x80;




 }
 void Timer_Start(void){
 //once prescaler connect will start counting
TCCR0 |= 0x05;
 // SET_BIT(TCCR0,0);
  //CLR_BIT(TCCR0,1);
 // SET_BIT(TCCR0,2);
 }
 void Timer_Stop(void){
 //stop clk
   CLR_BIT(TCCR0,0);
   CLR_BIT(TCCR0,1);
   CLR_BIT(TCCR0,2);
 }
 void Timer_Generate_Delay(uint8 delay_ms){
 uint8 Tick_Time=1024/16; //micro second
 Num_Tick=(delay_ms*1000)/Tick_Time;
 Num_OverFlow=Num_Tick/256;
 //float32 remider=(Num_Tick % 256);
 //Init_Value= 256-(remider * 256);
 Init_Value=256-(Num_Tick % 256);
 //Init_Value=256-((((float32)Num_Tick/256)-Num_OverFlow)*256)
 OCR0=Num_Tick-1;
 TCNT0=Init_Value;
 Num_OverFlow++;
 }

 void Timer0_SetCallBack(void (*p)(void)){
 pp=p;
 }

 ISR(TIMER0_OVF_vect){
	 static uint16 counter=0;
	 counter++;
	 if(counter == Num_OverFlow){
		 TCNT0=Init_Value;
		 counter=0;
		 (*pp)();
	 }
 }


 /*************************/
 void Timer1_Init(void){
 //mode CTC
 TCCR1B |= 0x08;
 //enable peripheral interrupt
  TIMSK |= 0x10;
  //enable general interrupt enable
  SREG|=0x80;

 }
 void Timer1_Start(void){
  //enable prescaller 1024
  TCCR1B|= 0x05;
 }
 void Timer1_Stop(void){
  //stop clk
  CLR_BIT(TCCR1B,0);
  CLR_BIT(TCCR1B,1);
  CLR_BIT(TCCR1B,2);
 }
 void Timer1_Generate_Delay(uint32 delay_ms){
 //first number sa7e7 instead in 4.192 4 sec is larg
 if(delay_ms < 4000){
 uint8 Tick_Time=1024/16;
 uint32 Num_Ticks= (delay_ms * 1000)/Tick_Time;
 //-1 for flag cycle
 OCR1AL=Num_Ticks-1;
 Compare_Match=1;
 }
 }
 void Timer1_SetCallBack(void (*p)(void)){
 timer1_ptr=p;
 }
 ISR(TIMER1_COMPA_vect){
 static uint32 count=0;
 count ++;
 if(count==Compare_Match){
 count=0;
 (*timer1_ptr)();
 }

 }

 //Fast PWM
 void PWM0_Init(){
 DDRB |=0x04;
 //initialize mode
 TCCR0 |=0x48;

 //Inverted or non Inverted PWM
 TCCR0 |=0x20;

 }
 //will use current stable value for frequency as it needed a lot of calculation
 //normal parameter is frequency and Duty cycle
 //freq=16M/(64*256)=Fosclator/(prescaller)*256 =974KHZ
 void PWM0_Generate(uint16 DutyCycle){
 OCR0= ((DutyCycle*256)/100)-1;
 }
 void PWM0_Start(void){
 TCCR0 |= 0x03;
 }
 void PWM1_Init(void){
 //enable mode 14
 TCCR1A |=0x02;
 TCCR1B |= 0x18;

 ICR1=1250; //for simulation 625 as prescalar max is 8M
 }
 void PWM1_Generate(uint16 DutyCycle){
 OCR1AL= ((DutyCycle* 1250)/100)-1;
 }
 void PWM1_Start(void){
 //prescalar 256
 TCCR1B |=0x04;
 }