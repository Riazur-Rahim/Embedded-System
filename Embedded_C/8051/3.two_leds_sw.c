#include<reg51.h>
sbit led1=P1^0;
sbit led2=P1^1;
sbit sw = P2^0;
void delay(unsigned int);
void main()
{
	led1=1;
	led2=0;
	while(1)
	{
		if(sw==0)
		{
			led1=~led1;
			delay(100);
			led2=~led2;
			
		}
	}
}
void delay(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++)
	{
		for(j=0;j<1000;j++);
	}
}