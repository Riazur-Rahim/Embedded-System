#include<reg51.h>
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
sbit BUSY = P1^7;
sfr LCD_DATA = 0x90;

void LCD_COMMAND_WRITE(unsigned char);

void LCD_DATA_WRITE(unsigned char);

void LCD_BUSY();

void LCD_INIT();

void DELAY_10_MILLI(unsigned char);

void main()
{
	unsigned char a, row,col;
	unsigned char K[][4]={{0,1,2,3},{4,5,6,7},{8,9,'A','B'},{'C','D','E','F'}};
	P2=0x0F;
	LCD_INIT();
	while(1)
	{
		//-------------------------------Row Scanning--------------------------------------------
		
			do{
				
				a=P1;
				a=a&0x0f;
				
			
			}while(a==0x0f);
			if(a==0x0E)
			{
					row=0;
			}
			else if(a==0x0D)
			{
					row=1;
			}
			else if(a==0x0B)
			{
					row=2;
			}
			else if(a==0x07)
			{
					row=3;
			}
				// -----------------Column Scanning ------------------------------------
			P2=0xF0;
			
			
			if(a==0xE0)
			{
					col=0;
			}
			else if(a==0xD0)
			{
					col=1;
			}
			else if(a==0xB0)
			{
					col=2;
			}
			else if(a==0x70)
			{
					col=3;
			}
		
			LCD_DATA_WRITE(K[row][col]);
			while(1);
		}
		
}	

	
		


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
void DELAY_10_MILLI(unsigned char f)
{
		unsigned int i,j;
		for(i=0;i<f;i++)
		{
			for(j=0;j<100;j++);
		
		}
	
}
