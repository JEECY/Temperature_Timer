//************************************
//************************************
// 	    	by：走路去散步
//   				2016.1.19
//------------------------------------
//  	    温度计电子钟
//************************************
//			缺点：定时器没调试好
#include "reg52.h"
#include "key.h"
void Time_Init();
int main()
{
    Init_1302();
	OLED_Init(); //OLED初始化
	Time_Init(); //定时器
	while(1)
	{
     getting();
	 xianshi1_DS1302();
     xianshi2_DS1302();			
	 ping0();
	 into1();
	 into3_21();
	 into3_31();
	 into1_21();
	 green=0;
	 delay(50);
	 green=1;
	 BJ_DS18B20();
	}
}
void Time_Init()
{
	TMOD=0X01;
	TH0=0x47;                  //(65536-47200)/256; //50ms
	TL0=0xa0;                  //(65536-47200)%256;
	EA=1;
	ET0=1;
	TR0=1;
}
void Time9()interrupt 1
{
	TH0=0x47;                  //(65536-47200)/256;
	TL0=0xa0;                  //(65536-47200)%256;
	if(MB==1)
	LQ++;	
}