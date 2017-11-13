#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar temp;
sbit beep=P3^3;
void delay(uint);
int a;
void main()
{
    while(1)
    {
        temp=0xfe;
        for(a=7;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1);
        }
        for(a=8;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_cror_(temp,1);
        }
        P1=0x00;
        delay(500);
        for(a=5;a>0;a--)
        {
            P1=0xff;
            delay(500);
            P1=0x00;
            delay(500);
        }
    }
}
void delay(uint z)
{
    int x,y;
    for(x=z;x>0;x--)
    for(y=110;y>0;y--);
}