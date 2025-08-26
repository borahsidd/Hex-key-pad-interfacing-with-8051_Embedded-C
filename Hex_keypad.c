#include<reg51.h>
#include "4bit_LCD.h"

sbit R1 = P2^0;     // Connecting keypad to Port 2
sbit R2 = P2^1;
sbit R3 = P2^2;
sbit R4 = P2^3;
sbit C1 = P2^4;
sbit C2 = P2^5;
sbit C3 = P2^6;
sbit C4 = P2^7;


///////////////////////////////////// Function to initialize serial communication
void initialize_serial()	
	{ 
	TMOD=0x20;  //use Timer 1, 8 bit ,auto reload
	TH1=0xFD;   //9600 baudrate
	SCON=0x50;
	TR1=1;     //start timer
	TI=1;
	}
////////////////////////////////////Function to transmit data_
void transmit(unsigned char cmd)
	{
	 while(TI==0);
	 SBUF=cmd;
	 TI=0;
	}
///////////////////////////////////Main function
void main()
{
	lcdinit();
	initialize_serial();
	C1=1; C2=1; C3=1; C4=1;
	while(1)
	{
		/////////////////////////////////////For fist row
		R1=0; R2=1; R3=1; R4=1;
		if(C1==0)
		{transmit('1');lcd_data('1'); delay(100);}
		else if(C2==0)
		{transmit('2');lcd_data('2');delay(100);}
		else if(C3==0)
		{transmit('3');lcd_data('3'); delay(100);}
		else if(C4==0)
		{transmit('A'); lcd_data('A');delay(100);}
		/////////////////////////////////////For second row
		R1=1; R2=0; R3=1; R4=1;
		if(C1==0)
		{transmit('4');lcd_data('4'); delay(100);}
		else if(C2==0)
		{transmit('5');lcd_data('5'); delay(100);}
		else if(C3==0)
		{transmit('6');lcd_data('6'); delay(100);}
		else if(C4==0)
		{transmit('B');lcd_data('B'); delay(100);}
		/////////////////////////////////////For 3rd row
		R1=1; R2=1; R3=0; R4=1;
		if(C1==0)
		{transmit('7'); lcd_data('7');delay(100);}
		else if(C2==0)
		{transmit('8');lcd_data('8'); delay(100);}
		else if(C3==0)
		{transmit('9');lcd_data('9'); delay(100);}
		else if(C4==0)
		{transmit('C');lcd_data('C'); delay(100);}
		///////////////////////////////////// For 4th row
		R1=1; R2=1; R3=1; R4=0;
		if(C1==0)
		{transmit('*'); lcd_data('*');delay(100);}
		else if(C2==0)
		{transmit('0'); lcd_data('0');delay(100);}
		else if(C3==0)
		{transmit('#');lcd_data('#'); delay(100);}
		else if(C4==0)
		{transmit('D');lcd_data('D'); delay(100);}
		
	}
}
