#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit sh=P1^0;
sbit DS=P1^1;
sbit st=P1^2;
sbit sh2=P1^3;
sbit DS2=P1^4;
sbit st2=P1^5;
sbit beep=P2^3;
uchar led_mod[]={0xe7,0xcf,0x9f,0x00,0x00,0x9f,0xcf,0xe7,
				 0xe7,0xf3,0xf9,0x00,0x00,0xf9,0xf3,0xe7,
				 0x81,0x81,0xc3,0xc3,0xe7,0xff,0xe7,0xe7};
uchar led_seg[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
void input(uchar c);
void output();
void input2(uchar r);
void output2();
void delay(uint z);
void main()
{
	int a,b;
	beep=0;
	while(P2==0xf6)
	{
		for(b=0;b<40;b++)
		{
			for(a=0;a<8;a++)
			{
				input(led_mod[a]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}
		for(b=0;b<20;b++)
		{
			for(a=0;a<8;a++)
			{
				input(0xff);
				input(0x00);
				delay(1);
				output();
			}
		}
	}
	while(P2==0xf5)
	{
		for(b=0;b<40;b++)
		{
			for(a=0;a<8;a++)
			{
				input2(led_mod[a+8]);
				input2(led_seg[a]);
				delay(1);
				output2();
			}
		}
		for(b=0;b<20;b++)
		{
			for(a=0;a<8;a++)
			{
				input2(0xff);
				input2(0x00);
				delay(1);
				output2();
			}
		}	
	}
	while(P2==0xf3)
	{
		for(b=0;b<20;b++)
		{
			for(a=0;a<8;a++)
			{
				input(led_mod[a+16]);
				input(led_seg[a]);
				input2(led_mod[a+16]);
				input2(led_seg[a]);
				delay(1);
				output();
				output2();
			}
		}
		for(b=0;b<10;b++)
		{
			for(a=0;a<8;a++)
			{
				input(0xff);
				input(0x00);
				input2(0xff);
				input2(0x00);
				delay(1);
				output();
				output2();
			}
		}	
	}
}
void input(uchar c)
{
	int d;
	for(d=0;d<8;d++)
	{
		c<<=1;
		DS=CY;
		sh=0;
		sh=1;
		sh=0;
	}	
}
void output()
{
	st=0;
	st=1;
	st=0;
}
void input2(uchar r)
{
	int s;
	for(s=0;s<8;s++)
	{
		r<<=1;
		DS2=CY;
		sh2=0;
		sh2=1;
		sh2=0;
	}	
}
void output2()
{
	st2=0;
	st2=1;
	st2=0;
}
void delay(uint z)
{	
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);
}