#define dataport P1

sbit rs=P1^0;
sbit rw=P1^1;
sbit e=P1^2;

//////////////////////////////////Delay program
void delay(unsigned int msec)
{
  int i,j;
  for(i=0;i<msec;i++)
	{
  for(j=0;j<1275;j++);
	}
}
////////////////////////////// Function to send command to LCD
void lcd_cmd(unsigned char item) 
{ 
	////////////////////////////Sending upper nibble of command
	unsigned char a;
	a=item&0xf0;
	dataport=a;
  rs=0;
  rw=0;
  e=1;
  delay(1);
  e=0;
	////////////////////////////Sending lower nibble of command
	a=(item<<4)&0xf0;
	dataport=a;
	rs=0;
  rw=0;
  e=1;
  delay(1);
  e=0;
}
//////////////////////////////// Function to send data to LCD

void lcd_data(unsigned char item) 
{ 
	////////////////////////////Sending upper nibble of data_
  unsigned char a;
	a=item&0xf0;
	dataport=a;
  rs=1;
  rw=0;
  e=1;
  delay(1);
  e=0;
	////////////////////////////Sending lower nibble of data_
	a=(item<<4)& 0xf0;
	dataport=a;
	rs=1;
  rw=0;
  e=1;
  delay(1);
  e=0;  
}
void lcdinit()
{
	lcd_cmd(0x33); // These two commands (0x33 and ox32) are used in 4 bit mode of LCD 
	lcd_cmd(0x32);
	lcd_cmd(0x28); //4 bit mode of LCD
	lcd_cmd(0x06); //display from left to right
	lcd_cmd(0x0C); //display ON, cursor hide
	lcd_cmd(0x01); //clear LCD
}