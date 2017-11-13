	  #include<reg52.h>
	  #define uint unsigned int	 
	  #define uchar unsigned char 
	  sbit p1=P1^3 ;
	  //void delay();
	  void delay(uint);
void main()
	  {
	   while(1)
	   {
	   p1=0;
	   delay(100);
	   p1=1;
	   delay(100);
	   }
	  }

/*void delay()
	  {
	  	 uint x,y;
		 for(x=100;x>0;x--)
		 for(y=2000;y>0;y--);
	  }*/
	  void delay(uint z)
	  {
	  	 uint x,y;
		 for(x=50;x>0;x--)
		 for(y=z;y>0;y--);
	  }
