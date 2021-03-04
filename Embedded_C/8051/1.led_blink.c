#include<reg51.h>
sbit led = P1^0;
void delay(unsigned int);
void main()
{
	while(1)
	{
		led = 1;
		delay(84);
		led = 0;
		delay(84);	//84 for 1 sec.
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