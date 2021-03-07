#include<reg51.h>
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
sbit BUSY = P1^7;
sfr LCD_DATA = 0x90;

void LCD_COMMAND_WRITE(unsigned char);

void LCD_DATA_WRITE(unsigned char);

void LCD_BUSY();

void LCD_INIT();

void DELAY_10_MILLI(unsigned char);

unsigned char str[] = {"Riazur Rahim"};

void LCD_COMMAND_WRITE(unsigned char Command)
{
	LCD_BUSY();
	RS = 0;
	RW = 0;
	LCD_DATA = Command;
	EN = 1;
	DELAY_10_MILLI(100);
	EN = 0;
}
void LCD_DATA_WRITE(unsigned char ch)
{
	LCD_BUSY();
	
	RS = 1;
	
	RW = 0;
	
	LCD_DATA = ch;
	
	EN = 1;
	
	DELAY_10_MILLI(100);
	
	EN = 0;
}
void LCD_BUSY()
{
	RS = 0;
	
	RW = 1;
	
	BUSY = 1;
	
	while(BUSY == 1)
	{
		EN = 0;
		DELAY_10_MILLI(100);
		EN = 1;
	
	
	}
}
void LCD_INIT()
{
	unsigned char Command[] = {0x38,0x0E,0x01,0x06,0x80};
	
	unsigned char i;

	for(i=0;i<5;i++)
	{
		LCD_COMMAND_WRITE(Command[i]);

	}
}
void main()
{
	unsigned char i;
	
	LCD_INIT();
	
	while(1)
	{
		
		for(i=0;str[i] != '\0';i++)
		{
			LCD_DATA_WRITE(str[i]);
		
		}
		DELAY_10_MILLI(100);
		
		LCD_COMMAND_WRITE(0x01);
	}
}
void DELAY_10_MILLI(unsigned char f)
{
		unsigned int i,j;
	
		for(i=0;i<f;i++)
		{
			for(j=0;j<100;j++);
		
		}
	
}