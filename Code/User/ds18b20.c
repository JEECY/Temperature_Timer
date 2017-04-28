#include "ds18b20.h"
#include "intrins.h"
uchar xs=0,Tem=0,Tem1=0,Tem2=0;
//*************************延时函数
void delay18(uint z)   
{
while(z--)
	{
        _nop_(); 
        _nop_(); 	
	}  
}
//*************************启动总线
void IIC_DS18B20()
{
	uchar x;
	DQ=1;
	delay18(8); 
	DQ=0;
	delay18(240);
	delay18(240); 
	DQ=1;
	delay18(60);  
	x=DQ;
	delay18(240);
	delay18(180);   
}
//*************************写数据
void write_DS18B20(uchar dat)
{
	uint i;
 	for(i=0;i<8;i++)
 	{
		DQ=0;
		delay18(1);
		DQ=dat&0x01;
		delay18(60);  
		DQ=1;
		dat>>=1;	  
	}
	delay18(1);
}
//***************************读数据
uchar read_DS18B20()
{
	uchar i,dat=0;
 	for(i=0;i<8;i++)
	{
		DQ=0;
		dat>>=1;
		delay18(1);
		DQ=1;
		delay18(1);
		if(DQ==1)
		dat|=0x80;
		delay18(60);
	}
 	return(dat);
}
//**************************读取当前温度
void ReadTem()
{
	uchar TL=0,TH=0;
	IIC_DS18B20();
	write_DS18B20(0xcc);	// 跳过读序号列号的操作
	write_DS18B20(0x44);	// 启动温度转换
	delay18(1000);
	IIC_DS18B20();
	write_DS18B20(0xcc);
	write_DS18B20(0xbe);    //读取温度寄存器等（共可读9个寄存器） 前两个就是温度
	delay18(1000);
	TL=read_DS18B20();
	TH=read_DS18B20();
	Tem1=TH<<4;           //高8位中后三位数的值
	Tem1+=(TL&0xf0)>>4;   //低8位中的高4位值加上高8位中后三位数的值   temp1室温整数值
	Tem2=TL&0x0f;         //小数的值
	Tem=((TH*256+TL)>>4);  //当前采集温度值除16得 实际温度值   整数
	xs=Tem2*0.0625*10;   //小数位,若为0.5则算为5来显示  小数
}
//**************************温度值显示
void search_DS18B20()
{
	 ReadTem();
	 shuzu[0]=Tem/10;
	 WD4=shuzu[0];
	 shuzu[1]=Tem%10;
	 WD5=shuzu[1];
	 shuzu[2]=xs;
	 WD6=shuzu[2];
}