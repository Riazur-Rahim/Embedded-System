#include<reg51.h>
void delay(unsigned int);
void main()
{			       //0    1	  2	3   4  	 5    6    7    8    9    A    b    C    d    E    F
	unsigned char seg[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
	unsigned int i;
	while(1)
	{
		for(i=0;i<=16;i++)
		{
			P2 = seg[i];
			delay(300);
		}
	}
}
void delay(unsigned int a)
{
	unsigned int x,y;
	for(x=0;x<a;x++)
	{
		for(y=0;y<1000;y++);
	}
}
