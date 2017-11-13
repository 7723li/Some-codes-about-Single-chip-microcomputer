#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
uchar led_seg[]={0xfe,0xfd};
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit button=P2^0;
sbit beep=P2^3;
void input(uchar g);
void output();
void led_show(uint d);
void delay(uint z);
void temp();
void main()
{
	int a,b,c;
	P2=0x00;
	if(button==0)
	{
		while(1)
		{
			for(c=30;c>3;c--)
			{
				P2=0x0c;
				led_show(c);
				P2=0x04;
				delay(40);
			}
			for(c=3;c>0;c--)
			{
				P2=0x00;
				led_show(c);
				P2=0x0c;
				delay(30);
			}
			for(b=3;b>0;b--)
			{	
				P2=0x02;
				led_show(b);
			}	
			for(a=57;a>0;a--)
			{	
				P2=0x01;
				led_show(a);
			}	
		}
	}
}
void led_show(uint d)
{
	int e,f,i;
	e=d/10;
	f=d%10;
	for(i=0;i<40;i++)
	{
		input(led_seg[0]);
		input(led_mod[e]);
		output();
		delay(5);
		input(led_seg[1]);
		input(led_mod[f]);
		output();
		delay(5);
	}	
}
void input(uchar g)
{
	int h;
	for(h=0;h<8;h++)
	{
		g<<=1;
		DS=CY;
		sh=0;
		_nop_();
		_nop_();
		sh=1;
		_nop_();
		_nop_();
	}
}
void output()
{
	st=0;
	_nop_();
	_nop_();
	st=1;
	_nop_();
	_nop_();
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);
}