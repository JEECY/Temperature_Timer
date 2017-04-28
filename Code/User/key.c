#include "key.h"
uchar R=0,R1=0,R2=0,b=0,b1=0,b2=0,e=0;
uchar LQ=0,MB=0,H4=0,K4=0,F4=0,MB1=0,MB2=0,MB3=0,MB4=0,FL1=0,FL2=0,KL1=0,KL2=0,HL1=0,HL2=0;
uchar hour=0,temp=0;
uchar ZD=0,ZD1=0;
uchar j1=0,j2=0,H1=0,H2=0,q1=0,q2=0,DS=0,DS1=0;
uchar date=0,day=0,month=0,year=0,Y2=0,Y1=0,N1=0,N2=0,R11=0,R21=0;
void into1(void);
void into1_1(void);
void into1_2(void);
void into1_21(void);
void into2(void);
void into3(void);
void into3_1(void);
void into3_2(void);
void into3_21(void);
void into3_3(void);
void into3_31(void);
void into3_4(void);
void menu_move1()
{
	if(KZ==0)
	{
	delay(5);
	if(KZ==0)
		{
		red=0;
		delay(5);
		red=1;
		b++;
		}
	while(!KZ);
	}
	if(b==1)
	{
	OLED_P16x16Ch(0,0,15);	 //箭头
	OLED_P16x16Ch(0,3,28);	 //清除箭头		
	OLED_P16x16Ch(0,6,28);
	R=1;
	}
	if(b==2)
	{
	OLED_P16x16Ch(0,3,15);	 //箭头
	OLED_P16x16Ch(0,0,28);	 //清除箭头		
	OLED_P16x16Ch(0,6,28);
	R=2;
	}
	if(b==3)
	{
	OLED_P16x16Ch(0,6,15);	 //箭头
	OLED_P16x16Ch(0,3,28);	 //清除箭头		
	OLED_P16x16Ch(0,0,28);
	R=3;
	b=0;
	}					 
}

void menu_move2()
{
	if(KZ==0)
	{
	delay(5);
	if(KZ==0)
		{
		red=0;
		delay(5);
		red=1;
		b1++;
		}
		while(!KZ);
	}
	if(b1==1)
	{
	OLED_P16x16Ch(0,0,15);	 //箭头
	OLED_P16x16Ch(0,2,28);	 //清除箭头		
	OLED_P16x16Ch(0,4,28);
	OLED_P16x16Ch(0,6,28);
	R1=1;
	}
	if(b1==2)
	{
	OLED_P16x16Ch(0,2,15);	 //箭头
	OLED_P16x16Ch(0,0,28);	 //清除箭头		
	OLED_P16x16Ch(0,6,28);
	OLED_P16x16Ch(0,4,28);
	R1=2;
	}
	if(b1==3)
	{
	OLED_P16x16Ch(0,4,15);	 //箭头
	OLED_P16x16Ch(0,2,28);	 //清除箭头		
	OLED_P16x16Ch(0,0,28);
	OLED_P16x16Ch(0,6,28);
	R1=3;
	}
	if(b1==4)
	{
	OLED_P16x16Ch(0,6,15);	 //箭头
	OLED_P16x16Ch(0,0,28);	 //清除箭头		
	OLED_P16x16Ch(0,2,28);
	OLED_P16x16Ch(0,4,28);
	R1=4;
	b1=0;
	}					 
}

void menu_move3()
{
	if(KZ==0)
	{
	delay(5);
	if(KZ==0)
		{
		red=0;
		delay(5);
		red=1;
		b2++;
		}
		while(!KZ);
	}
	if(b2==1)
	{
	OLED_P16x16Ch(0,2,15);	 //箭头
	OLED_P16x16Ch(0,5,28);	 //清除箭头		
	R2=1;					 //"成功"
	}
	if(b2==2)
	{
	OLED_P16x16Ch(0,5,15);	 //箭头
	OLED_P16x16Ch(0,2,28);	 //清除箭头		
	R2=2;
	b2=0;					 //“取消”
	}					 

}
//-----------------------
//		跳转至界面1
//-----------------------
void into1()
{
	if(KQ==0)
	{
		delay(5);
		if(KQ==0)
		{
			OLED_CLS(0);
			e=1;  
			while(e==1)
			{
				ping1();
				menu_move1();
				into2();
				if(KY==0)   //返回
				{
					delay(5);
					if(KY==0)
					{
						OLED_CLS(0);
						break;
					}
				}	
			}
			b=0;R=0;	
		}
	}
}
//+++++++++++++++++++++++
//  	日期调整
void into1_1()
{
if((R==2)&&(KQ==0))
	{
	delay(10);
	if(KQ==0)
		{
		OLED_CLS(0);
		getting();
        xianshi2_DS1302();
		while(R==2)
			{
		if(KZ==0)
			{
			delay(10);
			if(KZ==0)
				{
				red=0;
				delay(10);
				red=1;
				date++;
				if(date==4)
				date=1;
				}
				while(!KZ);
			}
			
		if((date==1)&&(KS==0))			        //年加
			{
             delay(10);
			 if(KS==0)
			 	{
				red=0;
				delay(50);
				red=1;
                temp=time[6]/16;
				time[6]=time[6]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[6]<99)
				time[6]++;

				else
				time[6]=0;
				year=time[6];

				temp=time[6]/10;
				time[6]=time[6]%10+temp*16;	  //再转换回BCD数
				OLED_P6x8Str(25,5,"2");
				OLED_P6x8Str(31,5,"0");
				OLED_RYN2(37,5,"0",N2,6);
				OLED_RYN1(45,5,"0",N1,6);				
				}
				while(!KS);
			}

		if((date==1)&&(KX==0))			        //年减
			{
             delay(10);
			 if(KX==0)
			 	{
				red=0;
				delay(50);
				red=1;
                temp=time[6]/16;
				time[6]=time[6]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[6]>0)
				time[6]--;

				else
				time[6]=99;
				year=time[6];

				temp=time[6]/10;
				time[6]=time[6]%10+temp*16;	  //再转换回BCD数
				OLED_P6x8Str(25,5,"2");
				OLED_P6x8Str(31,5,"0");
				OLED_RYN2(37,5,"0",N2,6);
				OLED_RYN1(45,5,"0",N1,6);				
				}
				while(!KX);
			}

		if((date==2)&&(KS==0))			        //月加
			{
             delay(10);
			 if(KS==0)
			 	{
				red=0;
				delay(50);
				red=1;
                temp=time[4]/16;
				time[4]=time[4]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[4]<12)
				time[4]++;

				else
				time[4]=1;
				month=time[4];

				temp=time[4]/10;
				time[4]=time[4]%10+temp*16;	  //再转换回BCD数
				OLED_RYN2(61,5,"0",Y2,4);
				OLED_RYN1(69,5,"0",Y1,4);				
				}
				while(!KS);
			}
		if((date==2)&&(KX==0))			        //月减
			{
             delay(10);
			 if(KX==0)
			 	{
				red=0;
				delay(50);
				red=1;
                temp=time[4]/16;
				time[4]=time[4]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[4]>1)
				time[4]--;

				else
				time[4]=12;
				month=time[4];

				temp=time[4]/10;
				time[4]=time[4]%10+temp*16;	  //再转换回BCD数
				OLED_RYN2(61,5,"0",Y2,4);
				OLED_RYN1(69,5,"0",Y1,4);				
				}
				while(!KX);
			}

		if((date==3)&&(KS==0))			        //日期加
			{
             delay(10);
			 if(KS==0)
			 	{
				red=0;
				delay(10);
				red=1;
                temp=time[3]/16;
				time[3]=time[3]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))&&(time[3]<32))
					{
					time[3]++;
					if(time[3]==32)
					time[3]=1;	   
					}

		 else if((year/400==0)&&(month==2)&&(time[3]<29))			 //闰年判断
		 		{
				time[3]++;
				if(time[3]==29)
				time[3]=1;
				}

		 else if((year/400!=0)&&(month==2)&&(time[3]<30))			 //非闰年判断
		 		{
				time[3]++;
				if(time[3]==30)
				time[3]=1;
				}

		 else if((time[3]<31)&&((month==4)||(month==6)||(month==9)||(month==11)))
		 	{
				time[3]++;
				if(time[3]==31)
				time[3]=1;
			}

				day=time[3];

				temp=time[3]/10;
				time[3]=time[3]%10+temp*16;	  //再转换回BCD数
                OLED_RYN2(85,5,"0",R21,3);
				OLED_RYN1(93,5,"0",R11,3);				
				}
				while(!KS);
			}

		if((date==3)&&(KX==0))			        //日期减
			{
             delay(10);
			 if(KX==0)
			 	{
				red=0;
				delay(10);
				red=1;
                 temp=time[3]/16;
				time[3]=time[3]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))&&(time[3]>0))
					{
					time[3]--;
					if(time[3]==0)
					time[3]=31;	   
					}

		 else if((year/400==0)&&(month==2)&&(time[3]>0))			 //闰年判断
		 		{
				time[3]--;
				if(time[3]==0)
				time[3]=28;
				}

		 else if((year/400!=0)&&(month==2)&&(time[3]>0))			 //非闰年判断
		 		{
				time[3]--;
				if(time[3]==0)
				time[3]=29;
				}

		 else if((time[3]>0)&&((month==4)||(month==6)||(month==9)||(month==11)))
		 	{
				time[3]--;
				if(time[3]==0)
				time[3]=30;
			}

				day=time[3];

				temp=time[3]/10;
				time[3]=time[3]%10+temp*16;	  //再转换回BCD数
                OLED_RYN2(85,5,"0",R21,3);
				OLED_RYN1(93,5,"0",R11,3);				
				}
				while(!KX);
			}
			
	   else if((KY==0)&&(date==1))
	   		{
			delay(10);
			if(KY==0)
				{
				red=0;
				delay(10);
				red=1;
				write_1302(0x8e,0x00);
				write_1302(0x8c,time[6]);		 //年
				write_1302(0x88,time[4]);		 //月
				write_1302(0x86,time[3]);        //日
				write_1302(0x8e,0x80);
				OLED_CLS(0);
				OLED_P16x16Ch(48,4,29);
				OLED_P16x16Ch(66,4,30);
				delay(6000);
				OLED_CLS(0);
				break;
				}
			
			}
	   else if((KY==0)&&(date==2))
	   		{
			delay(10);
			if(KY==0)
				{
				red=0;
				delay(10);
				red=1;
				OLED_CLS(0);
				OLED_P16x16Ch(48,4,31);
				OLED_P16x16Ch(66,4,32);
				delay(6000);
				OLED_CLS(0);
				break;
				}
			
			}																			
			}
		}
	}
}	
//+++++++++++++++++++++++
//  	温度显示
void into1_2()
{
  if((R==3)&&(KQ==0))
  	{
	delay(10);
	if(KQ==0)
		{
		 OLED_CLS(0);
		 OLED_P16x16Ch(24,2,33);
		 OLED_P16x16Ch(40,2,34);
		 OLED_P16x16Ch(24,5,31);
		 OLED_P16x16Ch(40,5,32);
		 while(R==3)
		 	{
		  menu_move3();
		  if(KY==0)
		  	{
			delay(10);
			if(KY==0)
				{
				OLED_CLS(0);
				OLED_P16x16Ch(50,4,29);
				OLED_P16x16Ch(78,4,30);
				delay(6000);
				OLED_CLS(0);
				break;
				}
			}
			}		
		}
	}
}
void into1_21()
{
	if(R2==1)
		{
		search_DS18B20(); 	
		xianshi_DS18B20();		//温度显示
		}
	if(R2==2)
	OLED_P8x16Str(0,0,"        ");
}

//-----------------------
//  	跳转至界面2
//-----------------------
void into2()
{
	if((R==1)&&(KQ==0))
	{
		delay(5);
		if(KQ==0)
		{
			OLED_CLS(0);
			while(R==1)
			{
				ping2();
				menu_move2();
				into3();
				if(KY==0)
				{
					delay(5);
					if(KY==0)
					{
						OLED_CLS(0);
						break;
					}
				}	
			}
		 b1=0;R1=0;
		}
	}
into1_1();	 //日期调整	         
into1_2();   
}
//+++++++++++++++++++++++
// 		界面2功能区
//+++++++++++++++++++++++
void into3()
{
 into3_1();
 into3_2();
 into3_3();
 into3_4();
}
//+++++++++++++++++++++++
// 		时间调整
void into3_1() 
{
if((R1==1)&&(KQ==0))
	{
	delay(10);
	if(KQ==0)
		{
		OLED_CLS(0);
		hour=1;
		getting();
		time[0]=0;
	    xianshi1_DS1302();        //显示日期
		while(R1==1)
		{	
		if(KZ==0)		//选择时位，分位
		{
		delay(10);
		if(KZ==0)
			{
				red=0;
				delay(10);
				red=1;
			hour=~hour;					   //取反
			}
			while(!KZ);
		}
		 
		 if((KS==0)&&(hour==1))			   //时加
		 {
		 delay(10);
		 if(KS==0)
		 	{	  
				red=0;
				delay(10);
				red=1;				
				temp=time[2]/16;
				time[2]=time[2]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[2]<23)
				time[2]++;

				else
				time[2]=0;

				temp=time[2]/10;
				time[2]=time[2]%10+temp*16;	  //再转换回BCD数
				OLED_MFS2(24,3,"0",S2,2);
                OLED_MFS1(32,3,"0",S1,2);
			} 
			while(!KS);
		}

		else if((KS==0)&&(hour==-2))						  //分加
			 {
		 		delay(10);
		 		if(KS==0)
		 		{
				red=0;
				delay(10);
				red=1;
				temp=time[1]/16;
				time[1]=time[1]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[1]<59)
				time[1]++;

				else
				time[1]=0;

				temp=time[1]/10;
				time[1]=time[1]%10+temp*16;
				OLED_MFS2(56,3,"0",F2,1);
                OLED_MFS1(64,3,"0",F1,1); 
			 	}
				while(!KS);
			 }


		 else if((KX==0)&&(hour==1))			  //时减
		 	{
			    
		     	 delay(10);
		      	 if(KX==0)
		 		{
				red=0;
				delay(10);
				red=1;
				temp=time[2]/16;
				time[2]=time[2]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[2]>0)
				time[2]--;

				else
				time[2]=23;

				temp=time[2]/10;
				time[2]=time[2]%10+temp*16;	  //再转换回BCD数
				OLED_MFS2(24,3,"0",S2,2);
                OLED_MFS1(32,3,"0",S1,2);
				}
				while(!KX);
			} 

		else if((KX==0)&&(hour==-2))			   //分减
			 {
			    delay(10);
		        if(KX==0)
		 		{
				red=0;
				delay(10);
				red=1;
				temp=time[1]/16;
				time[1]=time[1]%16+temp*10;	   //进行BCD数到十进制数的转换
				if(time[1]>0)
				time[1]--;

				else
				time[1]=59;

				temp=time[1]/10;
				time[1]=time[1]%10+temp*16;
				OLED_MFS2(56,3,"0",F2,1);
                OLED_MFS1(64,3,"0",F1,1); 
			 	}
				while(!KX);
			 }

		  else if((KY==0)&&(hour==1))					//修改成功
			{
			delay(10);
			if(KY==0)
				{
				write_1302(0x8e,0x00);
				write_1302(0x84,time[2]);
				write_1302(0x82,time[1]);
				write_1302(0x80,time[0]);
				write_1302(0x8e,0x80);
				OLED_CLS(0);
				OLED_P16x16Ch(48,4,29);
				OLED_P16x16Ch(66,4,30);
				delay(6000);
				OLED_CLS(0);
				break;
				}
			}

		  else if((KY==0)&&(hour==-2))					 //取消修改
			{
			delay(10);
			if(KY==0)
				{
				OLED_CLS(0);
				OLED_P16x16Ch(48,4,31);
				OLED_P16x16Ch(66,4,32);
				delay(6000);
				OLED_CLS(0);
				break;
				}
			}	  
		}
	}

}		 }
//+++++++++++++++++++++++
// 		整点报时
void into3_2()
{
if((R1==2)&&(KQ==0))
	{
	delay(10);
	if(KQ==0)
		{
		OLED_CLS(0);
		OLED_P16x16Ch(20,2,26);
		OLED_P16x16Ch(20,5,27);
		while(R1==2)
			{
			if(KZ==0)
				{
				delay(10);
				if(KZ==0)
					{
				red=0;
				delay(10);
				red=1;
				ZD++;
				if(ZD==3)
				ZD=1;
					}
					while(!KZ);
				}

				if(ZD==1)
				{
				OLED_P16x16Ch(0,2,15);	 //箭头
				OLED_P16x16Ch(0,5,28);	 //清除箭头
				ZD1=1;
				}
				if(ZD==2)
					{
				OLED_P16x16Ch(0,5,15);	 //箭头
				OLED_P16x16Ch(0,2,28);	 //清除箭头
				ZD1=2;
					}
																	
				if(KY==0)
					{
					delay(10);
					if(KY==0)
						{
				OLED_CLS(0);
				OLED_P16x16Ch(48,4,29);
				OLED_P16x16Ch(66,4,30);
				delay(6000);
				OLED_CLS(0);
				break;
						}
					}
			  }
		}
	}
}
void into3_21()
{
OLED_P16x16Ch(90,0,28);		//清除图标
if(ZD1==1)
	{
	OLED_P16x16Ch(90,0,35);		   //开启整点报时的图标
	if((time[1]==0)&&(time[0]==0))	
		{
		BS();
		}
	}

if(ZD1==2)
	{
	OLED_P16x16Ch(90,0,36);		   //关整点报时的图标
	if((time[1]==0)&&(time[0]==0))	
		{
		yellow=1;
		beep=1;
		}
	}
}
//+++++++++++++++++++++++
//		闹钟
void into3_3()
{
if((R1==3)&&(KQ==0))
	{
	delay(10);
	if(KQ==0)
		{
		OLED_CLS(0);
		OLED_MB1(40,3,"0",j1,H2);	   
		OLED_MB2(48,3,"0",j2,H2);
		OLED_P16x16Ch(56,3,2);
		OLED_MB1(72,3,"0",q1,H1);	   
		OLED_MB2(80,3,"0",q2,H1);

		OLED_P16x16Ch(20,6,26);
		OLED_P16x16Ch(100,6,27);
		while(R1==3)
	    	{
			if(KZ==0)
				{
				delay(10);
				if(KZ==0)
					{
					red=0;
					delay(10);
					red=1;
					DS++;
					if(DS==5)
					DS=1;	
					}
					while(!KZ);
				}
				if((DS==1)&&(KS==0))				 //时设定（加）
					{
					delay(10);
					if(KS==0)
						{
						if(H2<23)
						H2++;

						else
						H2=0;
						OLED_MB1(40,3,"0",j1,H2);	   
						OLED_MB2(48,3,"0",j2,H2);
						}
						while(!KS);
					}
				if((DS==1)&&(KX==0))				 //时设定（减）
					{
					delay(10);
					if(KX==0)
						{
                        if(H2>0)
						H2--;
						
						else
						H2=23;
						OLED_MB1(40,3,"0",j1,H2);	   
						OLED_MB2(48,3,"0",j2,H2);
						}
						while(!KX);
					}


				if((DS==2)&&(KS==0))				 //分设定（加）
					{
					delay(10);
					if(KS==0)
						{
						if(H1<59)
						H1++;

						else
						H1=0;
						OLED_MB1(72,3,"0",q1,H1);	   
						OLED_MB2(80,3,"0",q2,H1);
						}
						while(!KS);
					}
				if((DS==2)&&(KX==0))				 //分设定（减）
					{
					delay(10);
					if(KX==0)
						{
						if(H1>0)
						H1--;
						else
						H1=59;

						OLED_MB1(72,3,"0",q1,H1);	   
						OLED_MB2(80,3,"0",q2,H1);
						}
						while(!KX);
					}

				 if(DS==3)
				 	{
				 		OLED_P16x16Ch(0,6,15);	 //箭头
						OLED_P16x16Ch(84,6,28);	 //清除箭头
						DS1=1;	
				 	}
				if(DS==4)
					{
				 		OLED_P16x16Ch(84,6,15);	 //箭头
						OLED_P16x16Ch(0,6,28);	 //清除箭头										
						DS1=2;
					}

				if((DS==1)||(DS==2))
					{
					OLED_P16x16Ch(0,6,28);	 //清除箭头
					OLED_P16x16Ch(84,6,28);	 //清除箭头
					}
				if(KY==0)
					{
					delay(10);
					if((KY==0)&&((DS==1)||(DS==2)))
						{
						 OLED_CLS(0);
						 OLED_P16x16Ch(48,4,31);	//取消 
						 OLED_P16x16Ch(80,4,32);
						 delay(6000);
						 OLED_CLS(0);	
						 break;
						}
					}

				if((KY==0)&&((DS==4)||(DS==3)))
					{
					delay(10);
					if(KY==0)
						{
						 OLED_CLS(0);
						 OLED_P16x16Ch(48,4,29);	//成功 
						 OLED_P16x16Ch(80,4,30);
						 delay(6000);
						 OLED_CLS(0);	
						 break;
						}
					}				
			}
		}
	}
}
void into3_31()//定时判断
{
	temp=time[1]/16;
	time[1]=time[1]%16+temp*10;	   //进行BCD数到十进制数的转换
	temp=time[2]/16;
	time[2]=time[2]%16+temp*10;	   //进行BCD数到十进制数的转换
  	OLED_P16x16Ch(110,0,28);
 if(DS1==1)							 //开启闹钟
	{
	OLED_P16x16Ch(110,0,3);			 //图标
	if((time[2]==H2)&&(time[1]==H1))
		{
 		temp=time[1]/10;
		time[1]=time[1]%10+temp*16;
		temp=time[2]/10;
		time[2]=time[2]%10+temp*16;
		while(DS1==1)
			{
			OLED_CLS(3);
			OLED_MFS2(30,3,"0",S2,2);
			OLED_MFS1(38,3,"0",S1,2);
			OLED_P16x16Ch(46,3,2);
			OLED_MFS2(62,3,"0",F2,1);
			OLED_MFS1(70,3,"0",F1,1);
			BS();                    //蜂鸣器响
			delay(1000);

			if(KY==0)
				{
				delay(10);
				if(KY==0)
					{
					H2++;
					H1++;
					if(H2==24)
					H2=0;
					if(H1==60)
					H1=0;
					OLED_CLS(0);
					break;
					}
				}
			}

		}
	}
if(DS1==2)							//关闭闹钟
	{
	OLED_P16x16Ch(110,0,4);
	if((time[2]==H2)&&(time[1]==H1))
		{
		yellow=1;
		beep=1;
		}
	}
}
//+++++++++++++++++++++++
// 		秒表
void into3_4()
{
	if((R1==4)&&(KQ==0))
	{
		delay(5);
		if(KQ==0)
			{
			OLED_CLS(0);
			OLED_P8x16Str(36,0,"0");	   //初始化
			OLED_P8x16Str(44,0,"0");
			OLED_P8x16Str(52,0,".");
			OLED_P8x16Str(60,0,"0");	   
			OLED_P8x16Str(68,0,"0");
			OLED_P8x16Str(76,0,".");
			OLED_P8x16Str(84,0,"0");
			OLED_P8x16Str(92,0,"0");
			while(R1==4)
			{
			if(KZ==0)			  //开始计时
				{
				delay(5);
				if(KZ==0)
					{
					red=0;
	             	delay(50);
		            red=1;
                    MB++;
					if(MB==3)
					MB=1;
                	}
					while(!KZ);
				}
			if(MB==1)
			{
				if(LQ==20)
				{
					LQ=0;
					H4++;
				 if(H4==60)
					{
						H4=0;
						K4++;
					}
				if(K4==60)
					{
						K4=0;
						F4++;
					}
				if(F4==60)
					{
					F4=0;
					} 
				}
			}
			if(MB==2)
				{
				
				}
			if(KS==0)
				{
				delay(5);
				if(KS==0)
					{
					K4=0;
					H4=0;
					F4=0;
					}
					while(!KS);
				}
			OLED_MB1(36,0,"0",FL2,F4);		//时
			OLED_MB2(44,0,"0",KL2,F4);					
			OLED_MB1(60,0,"0",KL2,K4);		//分
			OLED_MB2(68,0,"0",KL1,K4);
			OLED_MB1(84,0,"0",HL2,H4);	    //秒
			OLED_MB2(92,0,"0",HL1,H4);
			delay(20);

		if(KX==0)			 //记时
		{
			delay(5);
			if(KX==0)
				{
				  MB1++;
				  if(MB1==4)
				  MB1=0;

		if(MB1==1)
		{
		MB2=F4;MB3=K4;MB4=H4;
			OLED_MB1(36,4,"0",FL2,MB2);		//时
			OLED_MB2(44,4,"0",FL1,MB2);
			OLED_P8x16Str(52,4,".");					
			OLED_MB1(60,4,"0",KL2,MB3);		//分
			OLED_MB2(68,4,"0",KL1,MB3);
			OLED_P8x16Str(76,4,".");
			OLED_MB1(84,4,"0",HL2,MB4);	    //秒
			OLED_MB2(92,4,"0",HL1,MB4);		
		}

		if(MB1==2)
		{
		MB2=F4;MB3=K4;MB4=H4;
			OLED_MB1(36,6,"0",FL2,MB2);		//时
			OLED_MB2(44,6,"0",FL1,MB2);
			OLED_P8x16Str(52,6,".");					
			OLED_MB1(60,6,"0",KL2,MB3);		//分
			OLED_MB2(68,6,"0",KL1,MB3);
			OLED_P8x16Str(76,6,".");
			OLED_MB1(84,6,"0",HL2,MB4);	    //秒
			OLED_MB2(92,6,"0",HL1,MB4);			
		}

		if(MB1==3)
		{
        OLED_CLS(4);			
		}
				}
				while(!KX);
		}



		if(KY==0)			//返回
			{
			delay(5);
			if(KY==0)
				{
				OLED_CLS(0);
				H4=0;K4=0;F4=0;
				break;
				}
			
		}											
			}
			}
	}
}


