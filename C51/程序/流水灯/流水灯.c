	   #include<reg52.h>
       #include<intrins.h>
	   #define uint unsigned int
	   #define uchar unsigned char
	 //sbit beep=P3^3;
	   sbit d1=P1^0;
       //sbit d2=P3^2;
	   uchar temp; 
	   void delay(uint);
	   void main()
	   {
        //IE=0x81;
		temp=0x7f;
		P1=temp;
              //beep=0;
		while(1)
	   {
		temp=_cror_(temp,1);
	    delay(600);
		P1=temp;		
		delay(600);
              //beep=1;
	    }
		}											 
	   void delay(uint z)
	   {
	   	uint x,y;
		for (x=30;x>0;x--)
		    for (y=z;y>0;y--);
	   }
      /*void XX()interrupt 0
       {
        if (d2=0)
        temp=0xff;
        P1=temp;
       }       */


	   