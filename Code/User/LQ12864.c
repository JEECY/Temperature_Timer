#include "LQ12864.h"
#include "codedata.h"
uchar time[7];
uchar WD1,WD2,WD3;
uchar shuzu[3];
uchar code table[60]=									  //���
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,
0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,
0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,
0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,
0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,
0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b
};
//--------------------
//     ʱ��
//--------------------
struct time
{
	uchar year1;
	uchar year2;
	uchar month1;
	uchar month2;
	uchar day1;
	uchar day2;
	uchar hour1;
	uchar hour2;
	uchar min1;
	uchar min2;
	uchar sec1;
	uchar sec2;
}Tim;
	/**********************************************
	//IIC Start
	**********************************************/
	void IIC_Start()
	{
	   SCL = high;		
	   SDA = high;
	   SDA = low;
	   SCL = low;
	}
	
	/**********************************************
	//IIC Stop
	**********************************************/
	void IIC_Stop()
	{
	   SCL = low;
	   SDA = low;
	   SCL = high;
	   SDA = high;
	}
	
	/**********************************************
	// ͨ��I2C����дһ���ֽ�
	**********************************************/
	void Write_IIC_Byte(unsigned char IIC_Byte)
	{
		unsigned char i;
		for(i=0;i<8;i++)
		{
			if(IIC_Byte & 0x80)
				SDA=high;		//���ͷ����ߣ�׼����������
			else
				SDA=low;
			SCL=high;			//�ͷ����ߣ����ݴ���
			SCL=low;			//�ȴ�
			IIC_Byte<<=1;
		}
		SDA=1;
		SCL=1;
		SCL=0;
	}
	
	/*********************OLEDд����************************************/ 
	void OLED_WrDat(unsigned char IIC_Data)
	{
		IIC_Start();
		Write_IIC_Byte(0x78);
		Write_IIC_Byte(0x40);			//����дģʽ
		Write_IIC_Byte(IIC_Data);
		IIC_Stop();
	}
	/*********************OLEDд����************************************/
	void OLED_WrCmd(unsigned char IIC_Command)
	{
		IIC_Start();
		Write_IIC_Byte(0x78);            //Slave address,SA0=0
		Write_IIC_Byte(0x00);			//write command
		Write_IIC_Byte(IIC_Command);
		IIC_Stop();
	}
	/*********************OLED ��������************************************/
	void OLED_Set_Pos(unsigned char x, unsigned char y) 
	{ 
		OLED_WrCmd(0xb0+y);			
		OLED_WrCmd(((x&0xf0)>>4)|0x10);
		OLED_WrCmd((x&0x0f)|0x01);
	} 
	/*********************OLEDȫ��************************************/
	void OLED_Fill(unsigned char bmp_dat) 
	{
		unsigned char y,x;
		for(y=0;y<8;y++)
		{
			OLED_WrCmd(0xb0+y);		//ˮƽ����
			OLED_WrCmd(0x01);		//��ֱ����
			OLED_WrCmd(0x10);
			for(x=0;x<X_WIDTH;x++)
			OLED_WrDat(bmp_dat);
		}
	}
	/*********************OLED��λ************************************/
	void OLED_CLS(unsigned char y)	   //y����ѡ����һ�㲻��ʾ
	{
		unsigned char x;
		for(;y<8;y++)
		{
			OLED_WrCmd(0xb0+y);
			OLED_WrCmd(0x01);
			OLED_WrCmd(0x10);
			for(x=0;x<X_WIDTH;x++)
			OLED_WrDat(0);
		}
	}
	/*********************OLED��ʼ��************************************/
	void OLED_Init(void)
	{
		delay(500);//��ʼ��֮ǰ����ʱ����Ҫ��
		OLED_WrCmd(0xae);//--turn off oled panel
		OLED_WrCmd(0x00);//---set low column address
		OLED_WrCmd(0x10);//---set high column address
		OLED_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
		OLED_WrCmd(0x81);//--set contrast control register
		OLED_WrCmd(Brightness); // Set SEG Output Current Brightness
		OLED_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
		OLED_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
		OLED_WrCmd(0xa6);//--set normal display
		OLED_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
		OLED_WrCmd(0x3f);//--1/64 duty
		OLED_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
		OLED_WrCmd(0x00);//-not offset
		OLED_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
		OLED_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
		OLED_WrCmd(0xd9);//--set pre-charge period
		OLED_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
		OLED_WrCmd(0xda);//--set com pins hardware configuration
		OLED_WrCmd(0x12);
		OLED_WrCmd(0xdb);//--set vcomh
		OLED_WrCmd(0x40);//Set VCOM Deselect Level
		OLED_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
		OLED_WrCmd(0x02);//
		OLED_WrCmd(0x8d);//--set Charge Pump enable/disable
		OLED_WrCmd(0x14);//--set(0x10) disable
		OLED_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
		OLED_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7) 
		OLED_WrCmd(0xaf);//--turn on oled panel
		OLED_Fill(0x00); //��ʼ����
		OLED_Set_Pos(0,0);
	} 
	/***************������������ʾ6*8һ���׼ASCII�ַ���	��ʾ�����꣨x,y����yΪҳ��Χ0��7****************/
	void OLED_P6x8Str(unsigned char x, y,unsigned char ch[])
	{
		unsigned char c=0,i=0,j=0;
		while (ch[j]!='\0')
		{
			c =ch[j]-32;	//(��32��Ӣ�Ĵ�Сдת������˼),�ӿո����ʼ
			if(x>126){x=0;y++;}		 //����
			OLED_Set_Pos(x,y);
			for(i=0;i<6;i++)   //����Ԫ�����һ���ַ�
			OLED_WrDat(F6x8[c][i]);
			x+=6;
			j++;
		}
	}
	/*******************������������ʾ8*16һ���׼ASCII�ַ���	 ��ʾ�����꣨x,y����yΪҳ��Χ0��7****************/
	void OLED_P8x16Str(unsigned char x, y,unsigned char ch[])
	{
		unsigned char c=0,i=0,j=0;
		while (ch[j]!='\0')
		{
			c =ch[j]-32;
			if(x>120){x=0;y++;}
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[c*16+i]);               //c*16Ϊѡ��ڼ���
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[c*16+i+8]);
			x+=8;
			j++;
		}
	}
	/*****************������������ʾ16*16����  ��ʾ�����꣨x,y����yΪҳ��Χ0��7****************************/
	void OLED_P16x16Ch(unsigned char x, y, N)
	{
		unsigned char wm=0;
		unsigned int adder=32*N;
		OLED_Set_Pos(x , y);
		for(wm = 0;wm < 16;wm++)
		{
			OLED_WrDat(F16x16[adder]);
			adder += 1;
		}
		OLED_Set_Pos(x,y + 1);
		for(wm = 0;wm < 16;wm++)
		{
			OLED_WrDat(F16x16[adder]);
			adder += 1;
		} 	  	
	}


 
	//*********************************************************************************************
	//***************************************ʱ����ʾ��BCD��
	//*********************************************************************************************
			
	void OLED_MFS1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)
	{
		unsigned char i=0,j=0;
		while (ch[j]!='\0')
		{
			if(x>120){x=0;y++;}
			SJ=time[L]%16;						   //��λ
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(SZ8X16[SJ*16+i]);              
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(SZ8X16[SJ*16+i+8]);
			x+=8;
			j++;
		}
	}
	
	void OLED_MFS2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)
	{
		unsigned char i=0,j=0;
		while (ch[j]!='\0')
		{
			if(x>120){x=0;y++;}	
			SJ=time[L]/16;					   //ʮλ
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(SZ8X16[SJ*16+i]);             
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(SZ8X16[SJ*16+i+8]);
			x+=8;
			j++;
		}
	}
	
	void OLED_RYN1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)
	{
		unsigned char i=0,j=0;
		while (ch[j]!='\0')
		{	
			if(x>126){x=0;y++;}
			SJ=time[L]%16;		   //��λ
			OLED_Set_Pos(x,y);
			for(i=0;i<6;i++)   //����Ԫ�����һ���ַ�
			OLED_WrDat(SZ6x8[SJ][i]);
			x+=6;
			j++;
		}
	}
	void OLED_RYN2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)
	{
		unsigned char i=0,j=0;
		while (ch[j]!='\0')
		{
			if(x>126){x=0;y++;}
			SJ=time[L]/16;		   //ʮλ
			OLED_Set_Pos(x,y);
			for(i=0;i<6;i++)   //����Ԫ�����һ���ַ�
			OLED_WrDat(SZ6x8[SJ][i]);
			x+=6;
			j++;
		}
	}
	
	//****************************ʱ��
	void xianshi1_DS1302()
	{
	OLED_MFS2(24,3,"0",Tim.hour2,2);
	OLED_MFS1(32,3,"0",Tim.hour1,2);
	OLED_P16x16Ch(40,3,2);
	OLED_MFS2(56,3,"0",Tim.min2,1);
	OLED_MFS1(64,3,"0",Tim.min1,1);
	OLED_P16x16Ch(72,3,2);
	OLED_MFS2(88,3,"0",Tim.sec2,0);
	OLED_MFS1(96,3,"0",Tim.sec1,0);
	}
	//*****************************����
	void xianshi2_DS1302()
	{
	OLED_P6x8Str(25,5,"2");
	OLED_P6x8Str(31,5,"0");
	OLED_RYN2(37,5,"0",Tim.year2,6);
	OLED_RYN1(45,5,"0",Tim.year1,6);
	OLED_P6x8Str(53,5,"-");
	OLED_RYN2(61,5,"0",Tim.month2,4);
	OLED_RYN1(69,5,"0",Tim.month1,4);
	OLED_P6x8Str(77,5,"-");
	OLED_RYN2(85,5,"0",Tim.day2,3);
	OLED_RYN1(93,5,"0",Tim.day1,3);
	}

 	//********************************************************************************************************
	//************��ʾ�¶�
	//********************************************************************************************************
	void OLED_TEM1(unsigned char x, y,unsigned char ch[])   //ʮλ
	{
		unsigned char c=0,i=0,j=0;
		while (ch[j]!='\0')
		{
			c =ch[j]-32;
			if(x>120){x=0;y++;}
			WD1=shuzu[0]+16;
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD1*16+i]);              
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD1*16+i+8]);
			x+=8;
			j++;
		}
	}
	
	
	void OLED_TEM2(unsigned char x, y,unsigned char ch[])	   //��λ
	{
		unsigned char c=0,i=0,j=0;
		while (ch[j]!='\0')
		{
			c =ch[j]-32;
			if(x>120){x=0;y++;}
			WD2=shuzu[1]+16;						   //�ӵ�ʮ���п�ʼΪ����
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD2*16+i]);               
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD2*16+i+8]);
			x+=8;
			j++;
		}
	}
	
	void OLED_TEM3(unsigned char x, y,unsigned char ch[])	  // С��λ
	{
		unsigned char c=0,i=0,j=0;
		while (ch[j]!='\0')
		{
			c =ch[j]-32;
			if(x>120){x=0;y++;}
			WD3=shuzu[2]+16;
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD3*16+i]);              
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WrDat(F8X16[WD3*16+i+8]);
			x+=8;
			j++;
		}
	}		
	
	void xianshi_DS18B20()
	{
	OLED_P16x16Ch(46,0,1);   //�¶ȷ���
	OLED_P16x16Ch(0,0,14);	 //�¶ȼƷ���
	OLED_TEM1(16,0,"0");
	OLED_TEM2(24,0,"0");
	OLED_P6x8Str(32,1,".");
	OLED_TEM3(38,0,"0");
	}
//--------------------
//		 ���
//--------------------
void OLED_MB1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)   	   //ʮλ
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{
		if(x>120){x=0;y++;}
		SJ=table[L]/10+16;
		OLED_Set_Pos(x,y);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[SJ*16+i]);              
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[SJ*16+i+8]);
		x+=8;
		j++;
	}
}
	
void OLED_MB2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L)   	   //��λ
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{
		if(x>120){x=0;y++;}
		SJ=(table[L]%10)+16;
		OLED_Set_Pos(x,y);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[SJ*16+i]);              
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[SJ*16+i+8]);
		x+=8;
		j++;
	}
}
