//multiple 8 leds

#include<reg51.h>

void delay(unsigned int);
void main()
{
	
	while(1)
	{
		P1 = 0x55;
		delay(84);
			P1 = 0xAA;
		delay(84);
	}
}
void delay(unsigned int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<1000;j++);
	}
}