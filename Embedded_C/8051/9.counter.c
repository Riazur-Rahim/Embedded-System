#include <reg51.h>

sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit BUZZER = P0^0;
void delay_1ms(unsigned int);

void main()
{
	unsigned int i;
	unsigned char str[] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F };
	
	BUZZER = 0;
	i = 0;
	
	while(1)
	{
		P1 = str[i];
		if( SW1 == 0 )
		{
			if( i >= 9)
			{
				BUZZER = 1;
				delay_1ms(100);
				BUZZER = 0;
			}
			else
			{
				P1 = str[++i];
				delay_1ms(100);
			}
			SW1 = 1;
		}
		if( SW2 == 0 )
		{
			if( i <= 0 )
			{
				BUZZER = 1;
				delay_1ms(100);
				BUZZER = 0;
			}
			else
			{
				P1 = str[--i];
				delay_1ms(100);
			}
			SW2 = 1;
		}
	}
}

void delay_1ms(unsigned int k)
{
	unsigned int i,j;
	for ( i = 0; i < k; i++ )
	{
		for ( j = 0; j < 110; j++ );
	}
}
