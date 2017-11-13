#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
uchar led_seg[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar temp;
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit sh1=P0^3;
sbit DS1=P0^4;
sbit st1=P0^5;
sbit button=P2^0;
sbit beep=P2^3;
void input(uchar g);
void output();
void input2(uchar w);
void output2();
void led_show(uint d);
void led_show2(uint m);
void delay(uint z);
void main()
{
	int a,b,c,l;
	beep=0;
	switch(P2 &	0xf7)
	{
		case 0xf5:	//NO.2
		temp=0x01;
		while(1)
		{
			{
				temp=0x01;
				for(l=0;l<8;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x03;
				for(l=0;l<7;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x07;
				for(l=0;l<6;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x0f;
				for(l=0;l<5;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x1f;
				for(l=0;l<4;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x3f;
				for(l=0;l<3;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0x7f;
				for(l=0;l<2;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				temp=0xff;
				for(l=0;l<1;l++)
				{
					input2(temp);
					temp=_crol_(temp,1);
					output2();
					delay(500);
				}
				input2(0xff);
				delay(800);
				for(l=0;l<100;l++)
				{
					input2(0x40);
					output2();
					delay(100);
					input2(0x80);
					output2();
					delay(100);
				}
			}
		}
		break;
		case 0xf3:	 //NO.3
		{
			int q;
			while(1)
			{
				for(q=0;q<10000;q++)
				{
					led_show2(q);
				}
				while(1)
				{
					for(q=0;q<100;q++)
					{
						led_show2(9999);
					}
					for(q=0;q<100;q++)
					{
						led_show2(0);
					}
				}
			}	
		}
		break;
		case 0xf6: //NO.1
		while(1)
		{
			for(c=30;c>3;c--)
			{
				input2(0x24);
				output2();
				beep=0;
				led_show(c);
				beep=1;
				delay(100);
			}
			for(c=3;c>=0;c--)
			{
				input2(0x24);
				output2();
				beep=0;
				led_show(c);
				beep=1;
				delay(40);
			}
			for(b=3;b>0;b--)
			{
				input2(0x12);
				output2();	
				beep=0;
				led_show(b);
			}	
			for(a=57;a>3;a--)
			{
				input2(0x09);
				output2();	
				beep=0;
				led_show(a);

			}
			for(a=3;a>0;a--)
			{
				input2(0x09);
				output2();	
				beep=0;
				led_show(a);
				beep=1;
				delay(40);

			}	
		} break;
		case 0xf7:input2(0xc0);output2();break;
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
		input(led_seg[2]);
		input(led_mod[e]);
		output();
		delay(5);
		input(led_seg[3]); 
		input(led_mod[f]);
		output();
		delay(5);
	}	
}
void input(uchar g)	 //shumaguan
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
void led_show2(uint m)
{
	int a1,a2,a3,a4,a5;
	a1=m/1000;
	a2=m/100%10;
	a3=m/10%10;
	a4=m%10;
	for(a5=0;a5<1;a5++)
	{
		input(led_seg[4]);
		input(led_mod[a1]);
		output();
		delay(5);
		input(led_seg[5]);
		input(led_mod[a2]);
		output();
		delay(5);
		input(led_seg[6]);
		input(led_mod[a3]);
		output();
		delay(5);
		input(led_seg[7]);
		input(led_mod[a4]);
		output();
		delay(5);
	}
}
void input2(uchar w)	//erjiguan
{
	int v;
	for(v=0;v<8;v++)
	{
		w<<=1;
		DS1=CY;
		sh1=0;
		_nop_();
		_nop_();
		sh1=1;
		_nop_();
		_nop_();
	}
}
void output2()
{
	st1=0;
	_nop_();
	_nop_();
	st1=1;
	_nop_();
	_nop_();
}
void delay(uint z)
{
	int x,y;
	for(x=0;x<70;x++)
	for(y=z;y>0;y--);
}