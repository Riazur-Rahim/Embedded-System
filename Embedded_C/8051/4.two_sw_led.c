#include<reg51.h>
sbit led = P1^0;
sbit sw1 = P2^0;
sbit sw2 = P3^0;

void main()
{
	sw1=1;
	sw2=1;
	while(1)
	{
		if(sw1==0)//checking whether sw1 is pressed or not.		bouncing time of switch is 10 ms
		{
			led=1;
		}
		if(sw2!=1)//sw2==0		checking whether sw2 is pressed or not.
		{
			led=0;
		}
		
	}
}