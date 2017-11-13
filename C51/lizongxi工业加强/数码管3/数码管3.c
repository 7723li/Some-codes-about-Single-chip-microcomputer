#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
uchar led_seg[]={0xfe,0xfd,0xfb,0xf7};
void delay(uint z);
void input(uchar i);
void output();
void led_show(uint b);
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit beep=P2^0;
void main()
{
	int a=0;
	beep=1;
	P0=0x00;
	while(a<10000)
	{
	switch(P2)
	{
		case 0xfb:a++;;break;
		case 0xf7:a--;break;
		case 0xfd:
			while(1)
			{
				for(;a<10000;a++)
				{
					led_show(a);
				}
			} break;
	}
	if(a<0)
	{
		a=0;	
	}
	led_show(a);
	}
}
void led_show(uint b)
{
	uint c,d,e,f;
	double g;
	c=b/1000;    //1256/1000=1 千位
	d=b/100%10;  //1256/100=12;12%10=2	百位
	e=b/10%10;    //1256/10=125;125%10=5 十位
	f=b%100%10;    //1256%100=56;56%10=6 个位
	for(g=0;g<5.2;g++)
	{
		input(led_seg[0]);
		input(led_mod[c]);
		output();
		delay(5);
		input(led_seg[1]);
		input(led_mod[d]);
		output();
		delay(5);
		input(led_seg[2]);
		input(led_mod[e]);
		output();
		delay(5);
		input(led_seg[3]);
		input(led_mod[f]);
		output();
		delay(5);
	}
	output();
}
void input(uchar i)
{
	int h;
	for(h=0;h<8;h++)
	{
		i<<=1;
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