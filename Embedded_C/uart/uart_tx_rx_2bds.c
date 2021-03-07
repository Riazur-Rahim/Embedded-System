#include<reg51.h>
#define led P1
sbit Q1=P2^0;
sbit Q2=P2^1;
void serial_Tx(unsigned char);
void serial_Rx();
void uart_init();
void delay(unsigned int);
void main()
{
	unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//,0x77,0x7C,0x39,0x5E,0x79,0x71};
	unsigned char i,j,m;
	uart_init();
	while(1)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				for(m=0;m<180;m++)
				{
					Q1=1;
					Q2=0;
					serial_Tx(seg[j]);
					delay(1);
					serial_Rx();
					delay(1);


					Q1=0;
					Q2=1;
					serial_Tx(seg[i]);
					delay(1);
					serial_Rx();
					delay(1);
				}
			}
		}
	}
}

void uart_init()
{
	TMOD = 0x20;		// mode 2 timer 1 
	SCON = 0x50;    // serial communication register mode 2 
	TH1=0xFD;				// baud_rate FD=9600 and we can write it as (-3), for 4800=FA (-6), 
	TR1=1;					// start the timer 1 which is in TCON
}

void serial_Tx(unsigned char dat)
{
	SBUF=dat;
	while(TI==0);			// checking for timer1 flag
	TI=0;							// clearing the flag
}

void serial_Rx()
{
	unsigned int dat2;
	while(RI==0);			//checking for reciever flag, waiting till data receive
	dat2=SBUF;				//storing the value from SBUF to the variable
	P1=dat2;					//value is sending to port 1
	RI=0;							//clearing the receiver flag
}

void delay(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++)
		for(j=0;j<20;j++);
}