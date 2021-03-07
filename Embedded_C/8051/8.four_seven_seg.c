#include<reg51.h>
#define led_display P2
sbit Q1=P1^0;
sbit Q2=P1^1;
sbit Q3=P1^2;
sbit Q4=P1^3;
void delay(unsigned int);
void main()
{
	unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//,0x77,0x7C,0x39,0x5E,0x79,0x71};
	while(1)
	{
		unsigned int i,j,k,m,n;
		unsigned int a,b,c,d;
		
		for(n=0;n<=9;n++)
		{
		for(m=0;m<=9;m++)
		{
			for(i=0;i<=9;i++)
			{
				for(j=0;j<=9;j++)
				{
					for(k=0;k<180;k++)
					{
						
						for(a=0;a<4;a++)
						{
							Q1=1;
							Q2=Q3=Q4=0;
							P0=seg[j];
						}
						
						delay(4);
						
						for(b=0;b<4;b++)
						{
							Q2=1;
							Q1=Q3=Q4=0;
							P0=seg[i];
						}
						
						delay(4);
						
						for(c=0;c<4;c++)
						{
							Q3=1;
							Q1=Q2=Q4=0;
							P0=seg[m];
						}
						
						delay(4);
						
						for(d=0;d<4;d++)
						{
							Q4=1;
							Q1=Q2=Q3=0;
							P0=seg[n];
						}
						
						delay(4);
						
					}
				}
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
		for(y=0;y<1;y++);
	}
}
