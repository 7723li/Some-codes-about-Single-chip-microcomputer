#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit sh=P1^0;
sbit DS=P1^1;
sbit st=P1^2;
sbit beep=P2^3;
uchar led_mod[]={0x81,0xbf,0xbf,0x81,0xbd,0xbd,0xbd,0x81,
				 0x81,0xfb,0xf7,0xef,0xef,0xef,0xef,0xef};	   //ÁÐ
uchar led_modno[]={0x81,0xef,0xef,0x00,0xef,0xcf,0xae,0x60};
uchar led_seg[]={0x01,0x02,0x04,0x08,0x10,0x29,0x40,0x80};		   //ÐÐ
void input(uchar i);
void output();
void delay(uint z);
void main()
{
	int a,b;
	beep=0;
	while(P2==0xf7)
	{
		for(b=0;b<80;b++)
		{
			for(a=0;a<8;a++)
			{
				input(led_mod[a]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}
		for(b=0;b<80;b++)
		{
			for(a=0;a<8;a++)
			{	 
				input(led_mod[a+8]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}
	}	
	while(P2==0xf6)
	{
		for(b=0;b<80;b++)
		{
			for(a=0;a<8;a++)
			{
				input(led_mod[a+8]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}	
	}
	while(P2==0xf5)
	{
		for(b=0;b<80;b++)
		{
			for(a=0;a<8;a++)
			{	 
				input(led_mod[a]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}
	}
	while(P2==0xf4)
	{
		for(b=0;b<80;b++)
		{
			for(a=0;a<8;a++)
			{	 
				input(led_modno[a]);
				input(led_seg[a]);
				delay(1);
				output();
			}
		}
	}		
}
void input(uchar i)
{
	int j;
	for(j=0;j<8;j++)
	{
		i<<=1;
		DS=CY;
		sh=0;
		sh=1;
	}		
}
void output()
{
	st=0;
	st=1;	
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<110;x++)
	for(y=z;y>0;y--);
}			