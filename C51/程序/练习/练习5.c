#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
uchar temp;
void delay(uint);
sbit D1=P1^0;
sbit D2=P3^3;
int a;
void main()
{
    while(1)
    {
        temp=0xfe;
        for(a=8;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0xfc;
        for(a=7;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0xf8;
        for(a=6;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0xf0;
        for(a=5;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0xe0;
        for(a=4;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0xc0;
        for(a=3;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0x80;
        for(a=2;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        temp=0x00;
        for(a=1;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        for(a=2;a>0;a--)
        {
            P1=0xff;
            delay(500);
            P1=0x00;
            delay(500);
        }
        P1=0x00;
        delay(500);
    }
}
void delay(uint z)
{
    int x,y;
    for(x=z;x>0;x--)
    for(y=110;y>0;y--);
}