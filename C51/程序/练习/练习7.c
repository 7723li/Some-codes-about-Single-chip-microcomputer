 #include<reg52.h>
 unsigned char led[]={0xfe,0xfd,0xfb,0xf7};
 void delay(unsigned char time)
 {
    unsigned int j=15000;
    for(;time>0;time--)
    for(;j>0;j--);
 }
 void main()
 {
    bit dir=0,run=0;
    char i;
    while(1)
    {
        switch(P2&0x0f)
        {
            case 0x0e:run=1;break;
            case 0x0d:run=0,dir=0;break;
            case 0x0b:dir=1;break;
            case 0x07:dir=0;break;
        }
        if(run)
        if(dir)
        for(i=0;i<=3;i++)
        {
            P1=led[i];
            delay(200);
        }
        else
        for(i=3;i>=0;i--)
        {
            P1=led[i];
            delay(200);
        }
        else P1=0xff;
    }
 }