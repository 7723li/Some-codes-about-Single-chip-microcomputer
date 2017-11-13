#include<reg52.h>
#include<intrins.h>
#define uint unsigned int 
#define uchar unsigned char
uchar led_mod[]={0xff,};
sbit sh=P0^3;
sbit DS=P0^4;
sbit st=P0^5; 
sbit button=P2^0;
uchar temp;
void delay(uint z);
void input(uchar i);
void output();
void main()
{
	int a,b;
	input(0xff);
	output();
	if(button==0)
	{
		while(1)
		{
			for(b=0;b<2;b++)
			{
				temp=0x01;
				for(a=0;a<8;a++)
				{
					input(temp);
					temp=_crol_(temp,1);
					delay(500);
					output();
				}
				temp=0x80;
				for(a=8;a>0;a--)
				{
					input(temp);
					temp=_cror_(temp,1);
					delay(500);
					output();
				}
			}
			temp=0x03;
			for(a=0;a<7;a++)
			{
					input(temp);
					temp=_crol_(temp,1);
					delay(500);
					output();	
			}	
		}
	}
}
void input(uchar i)
{
	int k;
	for(k=0;k<8;k++)
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
void delay(uint	z)
{
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);
}