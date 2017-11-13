#include<reg52.h>
#define uint unsigned int
void delay();
sbit p2_0=P2^0;
int a;
void iop()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TH1=(65536-50000)%256;
	ET0=1;
	TR0=1;
	EA=1;
}
void delay()
{
	uint c,b;
	for(c=0;c<400;c++)
	for(b=c;b>0;b--);
}			
void xx()interrupt 1
{
	TH0=(65536-50000)/256;
	TH1=(65536-50000)%256;
	TF0=0;
	a++;
}
void main()
{
	P2=0x00;
	delay();
	ET0=0;
	p2_0=!p2_0;
	ET0=1;
	while(1)
	{
		p2_0=0;
		delay();
		p2_0=1;
		delay()	;
	}	
}

