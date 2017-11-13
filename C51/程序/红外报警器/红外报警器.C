#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar code table[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71}; 
uchar code table1[]={0x80,0x40,0x20,0x10};
uchar code table2[]={0x10,0x20,0x40,0x80};

sbit P2_0=P2^0;
sbit P0_0=P0^0;
sbit P0_1=P0^1;
sbit P0_2=P0^2;
uchar htime;//红外时间变量
uchar startflag;//红外数据开始提取变量
uchar hdata[33];//红外数据的数组
uchar bytenumber;
uchar endflag;
uchar date[4];
uchar hp;
uchar disp[8];
void delay1(uint a)
{while(a--);
}
void delay(uint del)
{uint i,j;
 for(i=0;i<del;i++)
	for(j=0;j<110;j++);
}
void time0_init()
{TMOD=0x02;
 TH0=0x00;
 TL0=0x00;
 EA=1;
 ET0=1;
 TR0=1;
}
void int1init()
{EA=1;
 EX1=1;
 IT1=1;
}
//红外数据提取函数
void hpros()
{uchar k=1,i,j;
 uchar value;
 for(j=0;j<4;j++)
  {
   for(i=0;i<8;i++)
    { value=value>>1;
     if(hdata[k]>6)
	 {value=value|0x80;
	 }
     k++;
    }
    date[j]=value;
  }
  hp=1;
}
//红外数据处理函数
void hchuli()
{disp[0]=date[0]/16;
 disp[1]=date[0]%16;
 disp[2]=date[1]/16;
 disp[3]=date[1]%16;
 disp[4]=date[2]/16;
 disp[5]=date[2]%16;
 disp[6]=date[3]/16;
 disp[7]=date[3]%16;
}
//蜂鸣器发声和Led亮
void BEEP()
{uchar m=20;
 P0_0=0;
 while(m--)
  {P2_0=1;
   delay(1);
   P2_0=0;
   delay(1);
  }
 P0_0=1;
}
void main()
{uint i=0,k,flag=0,b=0,d=0,FLAG=1,rflag=1,RFLAG=1,alarm=0,G=0,g=0,rag=0;
 uchar key[8]={4,5,4,6,4,7,4,4},key1[8],key2[8]={4,0,4,3,0,7,1,5};//电控锁密码数组为key,key2为正转和反转，key1为转载红外数据的数组
 time0_init();
 int1init();
 while(1)
  { if(endflag)
     {hpros();
      endflag=0;
	 }
    if(hp)
      {hchuli();
       hp=0;
       flag=1;//按键按下蜂鸣器发声和led亮的标志
      }
     //电控锁复位标志
     if((disp[4]==1)&&(disp[5]==6))
	    {uchar a;
	     for(a=0;a<8;a++)
	      {key1[a]=0;}
	     FLAG=1;
	     rflag=1;
	     alarm=0;
         RFLAG=1;
		 i=0;
		}
     if(flag)
	    {BEEP();
	     key1[i]=disp[4];
	     key1[i+1]=disp[5];
	     i=i+2;
	     flag=0;
         rag=1;
	     alarm++;
         if(i==8)
          {i=0;}
		}
     //修改密码
    if((disp[4]==1)&&(disp[5]==9))
      { uchar a;
	     for(a=0;a<8;a++)
	      {key1[a]=0;}
       RFLAG=0;
       i=0;
      }

    //进入修改密码的具体的实现
	if(RFLAG==0)
      {
       //确认要修改的密码的原密码
       if((key[0]==key1[0])&&(key[1]==key1[1])&&(key[2]==key1[2])&&(key[3]==key1[3])&&(key[4]==key1[4])&&(key[5]==key1[5])&&(key[6]==key1[6])&&(key[7]==key1[7]))
	    {uint H;
          G=1;
         for(H=0;H<10;H++)
	        {  P0_1=0;
			   delay(20);
			   P0_1=1;
			   delay(20);
		    }	
          for(H=0;H<8;H++)
           {key1[H]=0;}
         i=0;
		 rag=0;
        }
       if((key2[0]==key1[0])&&(key2[1]==key1[1])&&(key2[2]==key1[2])&&(key2[3]==key1[3])&&(key2[4]==key1[4])&&(key2[5]==key1[5])&&(key2[6]==key1[6])&&(key2[7]==key1[7]))
	    {uint h;
          g=1;
         for(h=0;h<10;h++)
      		{P0_2=0;
			 delay(30);
			 P0_2=1;
			 delay(30);
			}
		  for(h=0;h<8;h++)
		    {key1[h]=0;}
		  i=0;
		  rag=0;
        }
       //修改密码，输入新密码
       if(G)
         {if(rag)
	        { uint B;
	          key[b]=disp[4];
	   		  key[b+1]=disp[5];
	          b=b+2;
	  		  if(b==8)
	           {b=0;
				G=0;
	            RFLAG=1;
	            alarm=0;
	            for(B=0;B<8;B++)
				 {key1[B]=0;
				 }
	            for(B=0;B<10;B++)
	        		{P0_1=0;
				     delay(20);
				     P0_1=1;
				     delay(20);
					}
				  i=0;
			    }
			   rag=0;
			 }
		  }
		if(g)
         {  if(rag)
			 {uint D;
	          key2[d]=disp[4];
	   		  key2[d+1]=disp[5];
	          d=d+2;
	  		  if(d==8)
	           {d=0;
				g=0;
	            RFLAG=1;
				alarm=0;
	            for(D=0;D<8;D++)
				 {key1[D]=0;
				 }
	            for(D=0;D<10;D++)
	        		{P0_2=0;
				     delay(20);
				     P0_2=1;
				     delay(20);
					}
	             i=0;
			    }
		      rag=0;
			 }
		  }
      }


    //红外控制电控锁旋转
    if(RFLAG)
     {
	    
	  
	   
	    if((key[0]==key1[0])&&(key[1]==key1[1])&&(key[2]==key1[2])&&(key[3]==key1[3])&&(key[4]==key1[4])&&(key[5]==key1[5])&&(key[6]==key1[6])&&(key[7]==key1[7]))
	      {uint j=128;
		   if(FLAG)
	        {P0_1=0;
			 while(j--)
	          {for(k=0;k<4;k++)
	            {P2=table1[k];
	             delay1(800);
			    }
	          }
			  P0_1=1;
	          FLAG=0;
	          rflag=1;
	          alarm=0;
			  i=0;
			}
	      }
		if((key2[0]==key1[0])&&(key2[1]==key1[1])&&(key2[2]==key1[2])&&(key2[3]==key1[3])&&(key2[4]==key1[4])&&(key2[5]==key1[5])&&(key2[6]==key1[6])&&(key2[7]==key1[7]))
	     { uint j=128;
          if(rflag)
	        {P0_2=0;
			 while(j--)
	          {for(k=0;k<4;k++)
	            {P2=table2[k];
	             delay1(800);
			    }
		      }
	         P0_2=1;
	         rflag=0;
		     FLAG=1;
	         alarm=0;
			 i=0;
		    }
		  }
         if((disp[4]==0)&&(disp[5]==9))
           {if(FLAG)
 			 {uchar n;
			  for(n=0;n<10;n++)
                {P0_1=0;
			     delay(20);
		         P0_1=1;
				 delay(20);
				}
             }
            if(rflag)
              {uchar m;
				for(m=0;m<10;m++)
                {P0_2=0;
			     delay(20);
		         P0_2=1;
				 delay(20);
				}
			  }
			disp[4]=0;
			disp[5]=0;
            i=0;
		   }
	    if(alarm>5)
	    {uint f=20;
	     while(f--)
	      {BEEP();}
	     i=0;
	     alarm=0;
		}
     }
  }
}
void time0() interrupt 1
{htime++;
}
void int1() interrupt 2
{ 
  if(startflag)
   {
    if(htime>35)
      bytenumber=0;
     hdata[bytenumber]=htime;
	 htime=0;
     bytenumber++;
    if(bytenumber==33) 
      {bytenumber=0;
	   endflag=1;
	  }
   }

  else 
    {
     startflag=1;
     htime=0;
	}
  
}