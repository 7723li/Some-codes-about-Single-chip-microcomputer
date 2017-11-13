#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
uchar temp;
void delay(uint);
sbit D1=P1^0;
sbit D2=P3^3;
int a,b;
void main()
{
    for(a=3;a>0;a--)
    {
        for(b=3;b>0;b--)
            {
                temp=0x55; //01010101
                delay(500);
                P1=temp;
            }
        for(b=3;b>0;b--)
            {
                temp=0xaa; //10101010
                delay(500);
                P1=temp;
            }
    }
    temp=0xfe;
    P1=temp;
    for(a=3;a>0;a--)
    {
        for(b=7;b>0;b--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        for(b=7;b>0;b--)
        {
            P1=temp;
            delay(500);
            temp=_cror_(temp,1);
        }
    }
    temp=0x7e;
    P1=temp;
    for(a=3;a>0;a--)
    {
        temp=0x7e;
        P1=temp;  //01111110
        delay(500);
        temp=0xbd;
        P1=temp;  //10111101
        delay(500);
        temp=0xdb;
        P1=temp;  //11011011
        delay(500);
        temp=0xe7;
        P1=temp;  //11100111
        delay(500);
        temp=0xdb;
        P1=temp;  //11011011
        delay(500);
        temp=0xbd;
        P1=temp;  //10111101
        delay(500);
        temp=0x7e;
        P1=temp;  //01111110
        delay(500);
    }
    temp=0x00;
    P1=temp;
    for(a=3;a>0;a--)
    {
        temp=0x00;
        delay(500);
        P1=temp;
        temp=0xff;
        delay(500);
        P1=temp;
    }
    P1=0xff;
    while(1);
}
void delay(uint z)
{
    int x,y;
    for(x=z;x>0;x--)
    for(y=110;y>0;y--);
}