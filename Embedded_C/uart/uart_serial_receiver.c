#include<reg51.h>
void uart_init();
void serial_Rx();
void main()
{
	unsigned char i;
	uart_init();
	while(1)
	{
		for(i=0;i<10;i++)
		{
			serial_Rx();
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
void serial_Rx()
{
	unsigned int dat2;
	while(RI==0);			//checking for reciever flag, waiting till data receive
	dat2=SBUF;				//storing the value from SBUF to the variable
	P1=dat2;					//value is sending to port 1
	RI=0;							//clearing the receiver flag
}
