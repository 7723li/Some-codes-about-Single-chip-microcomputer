#include <REG52.H>  
sbit LED = P1^0;  
unsigned char UART_buff;  
bit New_rec = 0, Send_ed = 1, Money = 0;  
//----------------------------------------------  
void serial_init()
{
	SCON = 0x50;   //���ڷ�ʽ1, 8-n-1, �������.  
    TMOD = 0x20;   //T1��ʽ2  
    TH1 = 0xFD;    
    TL1 = 0xFD;  
    TR1 = 1;                          
    ES  = 1;       //���ж�.  
    EA  = 1; 	
}

void main (void)  
{  
	serial_init();
    while(Money == 0);    //���Ž��ѣ��Ǻǣ����Ž���$.  
    while(1)  
	{   
		if ((New_rec == 1) && (Send_ed == 1))  //����յ������ݼ��������
		{    
	        SBUF = UART_buff; //�Ǿͷ���.  
	        New_rec = 0;  
	        Send_ed = 0;  
    	} 
	}  
}  

void ser_int (void) interrupt 4   
{  
    if(RI == 1) 
	{  //����յ�.  
      RI = 0;      //�����־.  
      New_rec = 1;  
      UART_buff = SBUF;  //����.  
      if(UART_buff == '1')  LED = 1;  
      if(UART_buff == '0')  LED = 0;  
      if(UART_buff == '$')  Money = 1;  
    }  
    else  
	{        //����ͱ�.  
      TI = 0;      //�����־.  
      Send_ed = 1;  
    }  
}   