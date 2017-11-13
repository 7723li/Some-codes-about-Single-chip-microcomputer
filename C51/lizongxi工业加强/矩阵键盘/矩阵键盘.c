#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char 
#define uint unsigned int
uchar led_mod[]={
0x3c,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0x3c
};
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit beep=P2^4;
void delay(uint z);
void input();
void output();
void led_show();
void main()
{
	while(1)
	{
		led_show();	
	}	
}
void led_show()
{
	
}