#include <REG52.H>  
sbit LED = P1^0;  
unsigned char UART_buff;  
bit New_rec = 0, Send_ed = 1, Money = 0;  
//----------------------------------------------  
void serial_init()
{
	SCON = 0x50;   //串口方式1, 8-n-1, 允许接收.  
    TMOD = 0x20;   //T1方式2  
    TH1 = 0xFD;    
    TL1 = 0xFD;  
    TR1 = 1;                          
    ES  = 1;       //开中断.  
    EA  = 1; 	
}

void main (void)  
{  
	serial_init();
    while(Money == 0);    //等着交费，呵呵，等着接收$.  
    while(1)  
	{   
		if ((New_rec == 1) && (Send_ed == 1))  //如果收到新数据及发送完毕
		{    
	        SBUF = UART_buff; //那就发送.  
	        New_rec = 0;  
	        Send_ed = 0;  
    	} 
	}  
}  

void ser_int (void) interrupt 4   
{  
    if(RI == 1) 
	{  //如果收到.  
      RI = 0;      //清除标志.  
      New_rec = 1;  
      UART_buff = SBUF;  //接收.  
      if(UART_buff == '1')  LED = 1;  
      if(UART_buff == '0')  LED = 0;  
      if(UART_buff == '$')  Money = 1;  
    }  
    else  
	{        //如果送毕.  
      TI = 0;      //清除标志.  
      Send_ed = 1;  
    }  
}   