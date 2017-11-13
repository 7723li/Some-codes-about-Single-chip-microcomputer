/*#include<reg52.h>	 //one
sbit wela=P2^6;
sbit dula=P2^7;
void main()
{
 wela=1;
 P0=0xfc;
 wela=0;
 dula=1;
 P0=0x66;
 dula=0;
 while(1);
} 		 */


#include<reg52.h>		  //two
#define GPIO_DIG P0	
unsigned char i;
sbit LSA=P2^4;
sbit LSB=P2^3;
sbit LSC=P2^2;
sbit beep=P1^5;
unsigned char code DIG_CODE[32]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char DisplayData[32];
//用来存放要显示的8位数的值
void DigDisplay(); //动态显示函数
void main(void)
{

	for(i=0;i<8;i++)
	//for(i=15;i>8;i--)
	{
		DisplayData[i]=DIG_CODE[i+8];	
	}
	while(1)
	{
		DigDisplay();
	}				
}			
	  
/*函 数 名         : DigDisplay
  函数功能		   : 使用数码管显示	*/
void DigDisplay()
{
    unsigned int j;
    for(i=0;i<8;i++)
	//for(i=15;i>8;i--)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(1):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(2):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(3):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(5):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(6):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(7):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第7位		
		}
		GPIO_DIG=DisplayData[i];//发送段码
		j=2000;					//扫描间隔时间设定
		while(j--);	
		GPIO_DIG=0x00;          //消隐	
	}
}

/*#include <reg52.h>	 //three
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^2;
sbit wela=P2^3;
sbit jkla=P2^4;
uchar num;
uchar code table[]=
{0x3f,0x06,0x5b,0x4f, 
 0x66,0x6d,0x7d,0x07,
 0x7f,0x6f,0x77,0x7c, 
 0x39,0x5e,0x79,0x71};
void delay(uint z);
void main()
{
  wela=1;
  P0=0xea;
  wela=0;
  while(1)
  {
   for (num=0;num<16;num++)
   {
    dula=1;
	P0=table [num];
	dula=0;
	{
	jkla=1;
	P0=0xea;
	jkla=0;
	}
   }
   delay (100);
  }
}
void delay(uint z)
{
   uint x,y;
   for(x=300;x>0;x--)
      for(y=z;y>0;y--);
}	   	  */

