//********************
//      按键函数
//********************
#ifndef _KEY_H
#define _KEY_H

#include "reg52.h"
#include "all.h"
#include "ds18b20.h"
#include "ds1302.h"
#include "beep.h"

sbit KS=P3^3;	  //加
sbit KX=P3^7;	  //减
sbit KZ=P3^4;	  //下移
sbit KY=P3^6;	  //返回
sbit KQ=P3^5;	  //确认

static uchar R,R1,R2,b,b1,b2;    //各菜单的选择标识符
static uchar e;   //界面1跳转标志符
static uchar date,day,month,year,Y2,Y1,N1,N2,R11,R21;  //日期调整
static uchar MB,H4,K4,F4,MB1,MB2,MB3,MB4,FL1,FL2,KL1,KL2,HL1,HL2;  //秒表标识符
extern uchar LQ;  //定时器标志
static uchar hour,temp,S1,S2,F1,F2;	   //时间调整
static uchar ZD,ZD1; //整点报时
static uchar j1,j2,H1,H2,q1,q2,DS,DS1;	//闹钟

void menu_move1(void); //界面1选择
void menu_move2(void); //界面2选择
void menu_move3(void); //界面3选择
void into1(void); 	//界面1
void into1_1(void); //日期调整
void into1_2(void); //温度调整
void into1_21(void);//温度显示
void into2(void);
void into3(void);
void into3_1(void);
void into3_2(void);
void into3_21(void);
void into3_3(void);
void into3_31(void);
void into3_4(void);

#endif