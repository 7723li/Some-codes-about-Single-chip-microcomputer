#include<reg52.h>
#define uint unsigned int
sbit p2_0=P2^0;
void delay()
{
	uint a,b;
	for(a=0;a<200;a++)
	for(b=a;b>0;b--) ;
}
void int0 () interrupt 0
{
	p2_0  = !p2_0;
	delay();
	while(1)
	{
		p2_0=0;
		delay();
		p2_0=1;
		delay();
	}
}
void main()
{
	IT0=1;
	IE=0x81;
	while(1);
}