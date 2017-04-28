#include "ds1302.h"

const uchar code READ_ADDR[7]={0x81,0x83,0x85,0x87,0x89,0x8B,0x8D};   //读地址 
const uchar code  WRITE_ADDR[7]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c}; //写地址
//======================
//DS1302写入一个字节函数
//======================
void write_byte13(uchar dat)
{
	uchar n;
	SCK1=0;
	for(n=0;n<8;n++)
		{
		SDA1=dat&0x01;
		SCK1=1;
		SCK1=0;
		dat>>=1;
		}
}
//======================
//DS1302读取一个字节函数
//======================
uchar read_byte13()
{
	uchar n,temp;
	for(n=0;n<8;n++)
		{
	    if(SDA1==1)
	    temp=(temp>>1)|0x80;
		else
		temp>>=1;
		SCK1=1;
		SCK1=0;
		}
	return(temp);	 
}		
//=============================
//读取数据（先写地址，再读数据）
//=============================
uchar read_1302(uchar addr)
{
	 uchar dat;
	 RT1=0;
	 SCK1=0;
	 RT1=1;
	 write_byte13(addr);
	 dat=read_byte13();
	 SCK1=1;
	 RT1=0;
	 return(dat);
}
//=========================
//写入数据（先地址，后数据）
//=========================
void write_1302(uchar addr,uchar dat)
{
	RT1=0;
	SCK1=0;
	RT1=1;
	write_byte13(addr);
	write_byte13(dat);
	SCK1=1;
	RT1=0;
} 
//==============
//	读取时间
//==============
void getting()
{
  uchar i;
  for(i=0;i<7;i++)
	{
	time[i]=read_1302(READ_ADDR[i]);
	}
}
//=================
//	初始化时间
//=================
void Init_1302()
{
	SCK1=0;  //拉低时钟信号
	RT1=0;   //复位ds1302
	RT1=1;   //使能ds1302
	write_1302(0x8e,0X00);//		  00
	write_1302(0x80,0x00);//second	  00
	write_1302(0x82,0x59);//minute	  59
	write_1302(0x84,0x23);//hour	  23
	write_1302(0x8a,0x05);//week	  05
	write_1302(0x86,0x24);//day		  24
	write_1302(0x88,0x08);//month	  08
	write_1302(0x8c,0x15);//year	  15
	write_1302(0x8e,0X80);//		  80
	RT1=0;   //复位
}
