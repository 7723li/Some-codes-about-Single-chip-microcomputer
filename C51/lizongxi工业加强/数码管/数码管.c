#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
uchar duanma[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
sbit button=P2^0;
sbit beep=P2^3;
void delay(uint);
void main()
{
	int a,b,x,y;
	beep=0;
	P2=0;
	delay(10);
	if(button==0)
	{
		beep=1;
		delay(500);
		for(a=0;a<100;a++)
		{
			beep=0;
			x=a/10;
			y=a%10;
			for(b=0;b<20;b++)
			{
				P1=0xfe;
				P0=led_mod[x];
				delay(5);
				P1=0xfd;
				P0=led_mod[y];
				delay(5);
			}
		}
	}	
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);	
}