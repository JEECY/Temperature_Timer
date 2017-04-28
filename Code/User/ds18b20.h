//******************************
//   温度传感器（注意芯片的使用）
//******************************
#ifndef _DS18B20_H
#define _DS18B20_H
#include "reg52.h"
#include "typedef.h"
sbit DQ=P2^2;
extern uchar WD4,WD5,WD6;
extern uchar shuzu[3];
void search_DS18B20(void);

#endif