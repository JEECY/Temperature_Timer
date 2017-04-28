//**********************
// 		Ê±ÖÓº¯Êý
//**********************
#ifndef _DS1302_H
#define _DS1302_H

#include "reg52.h"
#include "typedef.h" 
sbit SCK1=P1^5;
sbit SDA1=P1^6;
sbit RT1=P1^7;
extern uchar time[7];
void write_byte13(uchar dat);
uchar read_byte13();
uchar read_1302(uchar addr);
void write_1302(uchar addr,uchar dat);
void getting(void);
void Init_1302(void);

#endif