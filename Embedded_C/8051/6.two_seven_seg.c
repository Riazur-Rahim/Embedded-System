#include<reg51.h>
sbit Q1=P1^0;
sbit Q2=P1^1;
void delay(unsigned int);
void main()
{
							
	unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//,0x77,0x7C,0x39,0x5E,0x79,0x71};
	
	while(1)
	{
		unsigned int i,j,k;
		for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
			{
				for(k=0;k<1000;k++)
				{
					Q1=1;
					Q2=0;
					P3=seg[j];
					delay(1);
							
					Q1=0;
					Q2=1;
					P3=seg[i];
					delay(1);
				
			
				}
			}
		}
	}
}
void delay(unsigned int k)
{
	unsigned int x,y;
	for(x=0;x<k;x++)
	{
		for(y=0;y<50;y++);
	}
}
