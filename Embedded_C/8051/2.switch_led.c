#include<reg51.h>
sbit led = P1^0;
sbit sw = P2^0;
void delay(unsigned int a)
{
	unsigned int x,y;
	for(x=0;x<a;x++)
	{
		for(y=0;y<1000;y++);
	}
}
void main()
{
	sw=1;
	while(1)
	{
		while(sw==1);//checking switch is pressed or not
		delay(1);
		while(sw==1);
		while(sw==0);//checking switch is released or not
		led = ~led;
		delay(1);
		
	}
}