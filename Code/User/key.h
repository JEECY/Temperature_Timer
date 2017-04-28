//********************
//      ��������
//********************
#ifndef _KEY_H
#define _KEY_H

#include "reg52.h"
#include "all.h"
#include "ds18b20.h"
#include "ds1302.h"
#include "beep.h"

sbit KS=P3^3;	  //��
sbit KX=P3^7;	  //��
sbit KZ=P3^4;	  //����
sbit KY=P3^6;	  //����
sbit KQ=P3^5;	  //ȷ��

static uchar R,R1,R2,b,b1,b2;    //���˵���ѡ���ʶ��
static uchar e;   //����1��ת��־��
static uchar date,day,month,year,Y2,Y1,N1,N2,R11,R21;  //���ڵ���
static uchar MB,H4,K4,F4,MB1,MB2,MB3,MB4,FL1,FL2,KL1,KL2,HL1,HL2;  //����ʶ��
extern uchar LQ;  //��ʱ����־
static uchar hour,temp,S1,S2,F1,F2;	   //ʱ�����
static uchar ZD,ZD1; //���㱨ʱ
static uchar j1,j2,H1,H2,q1,q2,DS,DS1;	//����

void menu_move1(void); //����1ѡ��
void menu_move2(void); //����2ѡ��
void menu_move3(void); //����3ѡ��
void into1(void); 	//����1
void into1_1(void); //���ڵ���
void into1_2(void); //�¶ȵ���
void into1_21(void);//�¶���ʾ
void into2(void);
void into3(void);
void into3_1(void);
void into3_2(void);
void into3_21(void);
void into3_3(void);
void into3_31(void);
void into3_4(void);

#endif