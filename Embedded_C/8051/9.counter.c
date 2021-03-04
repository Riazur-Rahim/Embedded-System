#include<reg51.h>
#define led P2
sbit sw1=P1^0;
sbit sw2=P1^1;
	//2 doublts		1. while decreasing its coming to 0 and stoped		2. after increamenting, if we push sw2 for decreament, we have to push it 2 times.
void main()
{
	unsigned char seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//,0x77,0x7C,0x39,0x5E,0x79,0x71};
	unsigned int count,k=0,m,g;
	while(1)
	{
		
		for(m=k;m<=9;m++)
		{
			if(sw1 == 0)
			{
				led=seg[k];
				while(sw1==0);
				k=count++;
			}
		}		
		for(g=k;g<=count;g++)
		{
			if(sw2==0)
			{
				k=--count;
				if(k>=0 && k<=9)
				{
					led=seg[k];
					while(sw2==0);
				}
			}
		}
	}
}
