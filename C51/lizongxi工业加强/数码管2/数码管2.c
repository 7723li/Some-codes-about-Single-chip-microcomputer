#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
uchar led_seg[]={0xfe,0xfd};
void delay(uint z);
void input(uchar d);
void output();
void led_show(uint a);
void main()
{
	int b;
	P0=0x00;
	P2=0x00;
	while(1)
	{
		for(b=0;b<100;b++)
		{
			led_show(b);
		}	
	}
}
void led_show(uint a)
{
	int x,y,k;
	x=a/10;
	y=a%10;
	for(k=0;k<50;k++)
	{
		input(led_seg[0]);
		input(led_mod[x]);
		output();
		delay(5);
		input(led_seg[1]);
		input(led_mod[y]);
		output();
		delay(5); 
	}
}
void input(uchar d)
{
	uchar e;
	for(e=0;e<8;e++)
	{
		d<<=1;
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
	int g,h;
	for(h=0;h<110;h++)
	for(g=z;g>0;g--);
}