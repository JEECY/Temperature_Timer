//***********************
//   	OLED��������
//***********************
#ifndef _LQ12864_H
#define _LQ12864_H	
#include "reg52.h"
#include "delay.h"
#include "typedef.h"

sbit SCL=P1^1; //����ʱ��
sbit SDA=P1^0; //��������	
#define high 1
#define low 0	
#define	Brightness	0xCF 
#define X_WIDTH 	128
#define Y_WIDTH 	64
void IIC_Start(void);
void IIC_Stop(void);
void Write_IIC_Byte(unsigned char IIC_Byte);
void OLED_WrDat(unsigned char IIC_Data);
void OLED_WrCmd(unsigned char IIC_Command);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char bmp_dat);
void OLED_CLS(unsigned char y);
void OLED_Init(void);
void OLED_P6x8Str(unsigned char x, y,unsigned char ch[]);
void OLED_P8x16Str(unsigned char x, y,unsigned char ch[]);
void OLED_P16x16Ch(unsigned char x, y, N);
//----ʱ��
void OLED_MFS1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);
void OLED_MFS2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);
void OLED_RYN1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);
void OLED_RYN2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);
void xianshi1_DS1302(void);
void xianshi2_DS1302(void);
//----�¶�
void OLED_TEM1(unsigned char x, y,unsigned char ch[]);   //ʮλ
void OLED_TEM2(unsigned char x, y,unsigned char ch[]);	   //��λ
void OLED_TEM3(unsigned char x, y,unsigned char ch[]);	  // С��λ
void xianshi_DS18B20(void);
//----���
void OLED_MB1(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);   	   //ʮλ
void OLED_MB2(unsigned char x, y,unsigned char ch[],uchar SJ,uchar L);   	   //��λ

#endif