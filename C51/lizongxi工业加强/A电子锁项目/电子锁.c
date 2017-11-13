#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit sh=P0^0;
sbit DS=P0^1;
sbit st=P0^2;
sbit sh2=P1^0;
sbit DS2=P1^1;
sbit st2=P1^2;
sbit beep=P2^3;
sbit gr=P2^4;
sbit re=P2^5;
uchar led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};	 //字模
uchar led_seg[]={0xfe,0xfd,0xfb,0xf7};	 //位选
uchar password[]={0,1,2,3};		//密码
uchar saomiao();
uchar tempdate[4];				//四位储存
void input(uchar i);
void output();
void delay(uint z);
void main()
{
	uchar a=0,b,num;			
	uchar temp[4];			 //密码位数
	P2=0;
	beep=0;
	re=1;
	while(1)
	{
		num=saomiao();			
		if(num!=0xff)
		{
			if(a<4)
			{
				temp[a]=led_mod[num];
				tempdate[a]=temp[a];
				input(led_seg[a]);
				input(temp[a]);
				output();	
			}
			a++;
			if(a==4)
			{ 
				a=0;
				if((tempdate[0]==led_mod[password[0]])&&(tempdate[1]==led_mod[password[1]])&&(tempdate[2]==led_mod[password[2]])&&(tempdate[3]==led_mod[password[3]]))	 //密码判断正确
				{
				    gr=1;
					beep=1;
					re=0;
					delay(100);
					beep=0;	
					input(0x00);
					output();
					delay(300);
					gr=0;
					re=1;
				}
				else						   //密码错误
				{  
					input(0x00);
					output();
					b=5;
					while(b--)
					{
						beep=1;
						re=1;
						delay(100);
						beep=0;
						re=0;
						delay(100);
					} 
					a=15;
					while(a--)
					{
						re=1;
						delay(100);
						re=0;
						delay(100);
					}
					re=1;
				}
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
uchar saomiao() 
{
	uchar fortemp,revtemp,key;
	P3=0x0f;
	if(P3!=0x0f)
	{
		fortemp=P3;
		P3=0xf0;
		revtemp=P3;
		fortemp=fortemp|revtemp;
		while(P3!=0xf0)
		{
			switch(fortemp)
			{
				case 0xee:key=0;break;
				case 0xde:key=1;break;
				case 0xbe:key=2;break;
				case 0x7e:key=3;break;
				case 0xed:key=4;break;
				case 0xdd:key=5;break;
				case 0xbd:key=6;break;
				case 0x7d:key=7;break;
				case 0xeb:key=8;break;
				case 0xdb:key=9;break;
				case 0xbb:key=10;break;
				case 0x7b:key=11;break;
				case 0xe7:key=12;break;
				case 0xd7:key=13;break;
				case 0xb7:key=14;break;
				case 0x77:key=15;break;
				default:key=0xff;break;
			}
		}
	}
	else 
	key=0xff;
	return key;
}