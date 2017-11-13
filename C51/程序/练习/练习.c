 #include <reg52.h>
 sbit D1=P1^0; 
 sbit B1=P3^3;
 void delay();
 void main()
 {
    D1=0;
 }
/* void delay()
 {
    int x,y;
    for (x=0;x<=100;x++)
    for (y=0;y<100;y++);
 }       */