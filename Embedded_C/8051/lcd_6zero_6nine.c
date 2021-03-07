#include<reg51.h>
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
sbit BUSY = P1^7;
sfr LCD_DATA = 0x90;

void LCD_COMMAND_WRITE(unsigned char);
void LCD_DATA_WRITE(unsigned int);
void LCD_BUSY();
void LCD_INIT();
void DELAY_10_MILLI(unsigned char);

unsigned char str[] = {"0123456789"};

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
void LCD_DATA_WRITE(unsigned int ch)
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
	unsigned int i,j,a,b,c,d;
	
	LCD_INIT();
	while(1)
	{
		for(a=0;str[a]!='\0';a++)
		{	
			LCD_COMMAND_WRITE(0x80);	
			LCD_DATA_WRITE(str[a]);
			
				for(b=0;str[b]!='\0';b++)
			{
				LCD_COMMAND_WRITE(0x81);	
				LCD_DATA_WRITE(str[b]);
				
				for(c=0;str[c]!='\0';c++)
				{
					LCD_COMMAND_WRITE(0x82);	
					LCD_DATA_WRITE(str[c]);
					
					for(d=0;str[d]!='\0';d++)
					{
						LCD_COMMAND_WRITE(0x83);	
						LCD_DATA_WRITE(str[d]);
						
						for(i=0;str[i]!='\0';i++)
						{
							LCD_COMMAND_WRITE(0x84);	
							LCD_DATA_WRITE(str[i]);
							
							for(j=0;str[j]!='\0';j++)
							{
								LCD_COMMAND_WRITE(0x85);	
								LCD_DATA_WRITE(str[j]);
								
							}
						}
					}
				}
			}
		}
	
	}
}
void DELAY_10_MILLI(unsigned char f)
{
		unsigned int i,j;
	
		for(i=0;i<f;i++)
		{
			for(j=0;j<60;j++);
		
		}
	
}