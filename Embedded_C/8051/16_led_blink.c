#include<reg51.h>

void delay(unsigned int);
void main()
{
	unsigned char seg[10]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0xFF};
//	unsigned char seg[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

	unsigned int i,j;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P1 = seg[i];
			delay(84);
		}
		for(j=0;j<10;j++)
		{		
			P2 = 0xff;
			delay(84);
			P2 = 0x00;
			delay(84);
			P2=0x55;
			delay(84);
			P2=0xAA;
			delay(84);
		}
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