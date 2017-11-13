	   #include<reg52.h>
	   sbit p1=P1^4;
	   unsigned int a;
	   void main()
	   {
	   
	   a=50000;
	   p1=0;
	   while(a--);
	   a=50000;
	   p1=0;
	   while(a--);
	   a=50000;
	   p1=1;
	   while(a--);
	   a=50000;
	   p1=1;
	   while(a--);
	   }
	   