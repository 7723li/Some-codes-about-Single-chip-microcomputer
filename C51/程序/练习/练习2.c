#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
void delay(uint);
uchar temp;
int i;
sbit beep=P2^3;
void main()
{
temp=0xfe;
while(1)
{
for(i=7;i>0;i--)
{
P1=temp;
delay(500);
temp=_crol_(temp,1);
}
for(i=7;i>0;i--)
{
P1=temp;
delay(500);
temp=_cror_(temp,1);
}
}
}
void delay(uint z)
{
uint x,y;
for(x=z;x>0;x--)
for(y=110;y>0;y--);
}
 