//***********************
//     	·äÃùÆ÷
//***********************
#ifndef _BEEP_H
#define _BEEP_H

#include "reg52.h"
#include "typedef.h"
#include "delay.h"
sbit beep=P2^3;
sbit red=P1^3;		   //ÔİÍ£
sbit yellow=P1^4;	   //ÄÖÖÓ
sbit green=P1^2;	   //ÔËĞĞ

void BJ_DS18B20(void);
void BS(void);

#endif