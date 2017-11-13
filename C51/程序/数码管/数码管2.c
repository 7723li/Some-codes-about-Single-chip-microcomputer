	  #include <reg52.h>
	  #include <intrins.h>
	  #define uchar unsigned char
	  #define uint unsigned int
	  sbit A=P2^4;
	  sbit LSB=P2^3;
	  sbit C=P2^2;
	  uchar code table[]={
	  0x3f , 0x06 , 0x5b , 0x4f , 
	  0x66 , 0x6d , 0x7d , 0x07 ,
	  0x7f , 0x6f , 0x77 , 0x7c ,
	  0x39 , 0x5e , 0x79 , 0x71 } ;
	  uchar temp,num,aa;
	  void delay(uint z);
	  void main()	 //流水灯
{
	  while(1)
	  num=0;
	  aa=0;
	  TMOD=0x01;
      TH0=(65536-50000)/256;
	  TL0=(65536-50000)%256;
	  EA=1;
	  ET0=1;
	  TR0=1;
      temp=0xfe;
	  P1=temp;
	  
	  {
        aa++;
		num++;
	  	temp=_crol_(temp,1);
		P0=temp;
		P0=table[num];
		delay (100);	  
      }
}
 	  
	  void delay(uint z)  //延时函数
	  {
	   uint x,y;
	   for (x=100;x>0;x--)
	        for (y=z;y>0;y--);
	  }
      
	  void timer() interrupt 1		//中断函数
{	  	 
         uint i;
         switch(i)
	   {
	     if(aa==8)
			aa==0;
		 if(num==16)
		    num==0;
	     case(0):
		 A=0;LSB=0;C=0;break;
	   	 case(1):
		 A=1;LSB=0;C=0;break;
		 case(2):
		 A=0;LSB=1;C=0;break;
		 case(3):
		 A=1;LSB=1;C=0;break;
		 case(4):
		 A=0;LSB=0;C=1;break;
		 case(5):
		 A=1;LSB=0;C=1;break;
		 case(6):
		 A=0;LSB=1;C=1;break;
		 case(7):
		 A=1;LSB=1;C=1;break;
	   }
}	  



/*
#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp,aa,num;
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void delay(uint z);
void main()
{
	num=0;
	aa=0;
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	temp=0xfe;
	P1=temp;
	dula=1;
	P0=table[0];
	dula=0;
	wela=1;
	P0=0xc0;
	wela=0;
	while(1)
	{
		delay(1000);
		temp=_crol_(temp,1);
		P1=temp;
		if(aa==40)
			{
				aa=0;
				num++;
				if(num==16)
					num=0;
				dula=1;
				P0=table[num];
				dula=0;		
			}		
	}
}

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void timer0() interrupt 1 
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	aa++;
		if(aa==40)
			{
				aa=0;
				num++;
				if(num==16)
					num=0;
				dula=1;
				P0=table[num];
				dula=0;		
			}	
}						*/
 
	    