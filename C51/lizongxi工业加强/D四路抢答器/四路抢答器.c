#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit sh2=P0^3;
sbit DS2=P0^4;
sbit st2=P0^5;
sbit beep=P2^3;
sbit gr=P2^4;
sbit re=P2^5;
uchar led_seg[]={0xfd,0xfd};
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
void input(uchar d);
void output();
void input2(uchar i);
void output2();
void delay(uint z);
void main()
{
	int a;
	beep=0;
	gr=0;
	re=0;
	input2(0x55);
	output2();
	switch(P2)
	{
		case 0x87:
		input(led_seg[0]);
		input(led_mod[0/10]);
		input(led_seg[1]);
		input(led_mod[0%10]);
		a=5;
		while(a--)
		{
			beep=1;
			input2(0x95);
			output2();
			delay(5);
			input(0x15);
			output2();
		    delay(5);
			beep=0;
		}break;
		case 0xc3:
		input(led_seg[0]);
		input(led_mod[1/10]);
		input(led_seg[1]);
		input(led_mod[1%10]);
		a=5;
		while(a--)
		{
			beep=1;
			input2(0x65);
			output2();
			delay(5);
			input(0x45);
			output2();
		    delay(5);
		}break;
		case 0xc5:
		input(led_seg[0]);
		input(led_mod[2/10]);
		input(led_seg[1]);
		input(led_mod[2%10]);
		a=5;
		while(a--)
		{
			beep=1;
			input2(0x15);
			output2();
			delay(5);
			input(0x95);
			output2();
		    delay(5);
		}break;
		case 0xc6:
		input(led_seg[0]);
		input(led_mod[0/10]);
		input(led_seg[1]);
		input(led_mod[0%10]);
		a=5;
		while(a--)
		{
			beep=1;
			input2(0x45);
			output2();
			delay(5);
			input(0x65);
			output2();
		    delay(5);
		}break;
	}	
}
void input(uchar d)
{
	int e;
	for(e=0;e<8;e++)
	{
		DS=CY;
		d<<=1;
		sh=0;
		sh=1;
	}
}
void output()
{
	st=0;
	st=1;
}
void input2(uchar i)
{
	int j;
	for(j=0;j<8;j++)
	{	
		i<<=1;
		DS2=CY;
		sh2=0;
		sh2=1;
	}
}
void output2()
{
	st2=0;
	st2=1;
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<125;x++)
	for(y=z;z>0;y--);
}