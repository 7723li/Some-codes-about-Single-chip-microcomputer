#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit beep=P3^3;
sbit D1=P3^2;
int a;
uchar temp;  
void delay(uint);
void main()
{
    temp=0xfe;
    beep=0;
    IE=0x81;
    while(1)
    {
        for (a=7;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_crol_(temp,1); 
        }
        for(a=7;a>0;a--)
        {
            P1=temp;
            delay(500);
            temp=_cror_(temp,1);
        }
    }
}
void xx()interrupt 0
{
    if (D1==0);
    temp=0x00;
    beep=1;
    P1=temp;
    delay(100);
    if (D1==1);
    temp=0xfa;
    P1=temp;
    beep=0;
}
void delay(uint z)
{
    uint x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);
}