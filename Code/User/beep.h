//***********************
//     	������
//***********************
#ifndef _BEEP_H
#define _BEEP_H

#include "reg52.h"
#include "typedef.h"
#include "delay.h"
sbit beep=P2^3;
sbit red=P1^3;		   //��ͣ
sbit yellow=P1^4;	   //����
sbit green=P1^2;	   //����

void BJ_DS18B20(void);
void BS(void);

#endif