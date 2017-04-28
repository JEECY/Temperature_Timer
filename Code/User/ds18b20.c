#include "ds18b20.h"
#include "intrins.h"
uchar xs=0,Tem=0,Tem1=0,Tem2=0;
//*************************��ʱ����
void delay18(uint z)   
{
while(z--)
	{
        _nop_(); 
        _nop_(); 	
	}  
}
//*************************��������
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
//*************************д����
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
//***************************������
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
//**************************��ȡ��ǰ�¶�
void ReadTem()
{
	uchar TL=0,TH=0;
	IIC_DS18B20();
	write_DS18B20(0xcc);	// ����������кŵĲ���
	write_DS18B20(0x44);	// �����¶�ת��
	delay18(1000);
	IIC_DS18B20();
	write_DS18B20(0xcc);
	write_DS18B20(0xbe);    //��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	delay18(1000);
	TL=read_DS18B20();
	TH=read_DS18B20();
	Tem1=TH<<4;           //��8λ�к���λ����ֵ
	Tem1+=(TL&0xf0)>>4;   //��8λ�еĸ�4λֵ���ϸ�8λ�к���λ����ֵ   temp1��������ֵ
	Tem2=TL&0x0f;         //С����ֵ
	Tem=((TH*256+TL)>>4);  //��ǰ�ɼ��¶�ֵ��16�� ʵ���¶�ֵ   ����
	xs=Tem2*0.0625*10;   //С��λ,��Ϊ0.5����Ϊ5����ʾ  С��
}
//**************************�¶�ֵ��ʾ
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