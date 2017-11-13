#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
//uchar temp;
sbit p32=P3^2;
sbit beep=P3^3;
void delay(uint);
void main()
{
	int a,b;
	beep=0;
	P2=0x01;
	if(p32 == 0 )
	{
		beep=0;
		for(a=0;a<7;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		for(a=7;a>0;a--)
		{
			P2=_cror_(P2,1);
			delay(500);	
		}
		for(a=0;a<7;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0x81;
		for(a=0;a<7;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0x83;
		for(a=0;a<6;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0x87;
		for(a=0;a<5;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0x8f;
		for(a=0;a<4;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0xbf;
		for(a=0;a<3;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0xef;
		for(a=0;a<2;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		P2=0xff;
		for(a=0;a<1;a++)
		{
			P2=_crol_(P2,1);
			delay(500);
		}
		for(b=0;b<8;b++)
		{
			P2=0xff;
			beep=1;
			delay(500);
			P2=0x00;
			beep=0;
			delay(500);		
		}
		while(1);
	}
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);
}