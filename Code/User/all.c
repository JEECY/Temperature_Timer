#include "all.h"
void ping0()
{
        uchar i;
		for(i=0;i<8;i++)	   //按键提示
		{
		OLED_P6x8Str(24,7,"Press");
		OLED_P6x8Str(54,7," ");
		OLED_P6x8Str(60,7,"Any");
		OLED_P6x8Str(78,7," ");
		OLED_P6x8Str(84,7,"Keys");
		delay(500);
		OLED_CLS(7);
		}
}
void ping1()						    //主菜单
{
		OLED_P8x16Str(20,0,"1");	   //“1.时间设置”
		OLED_P8x16Str(28,0,".");
		OLED_P16x16Ch(36,0,5);
		OLED_P16x16Ch(52,0,6);
		OLED_P16x16Ch(68,0,18);
		OLED_P16x16Ch(84,0,19);
		
		OLED_P8x16Str(20,3,"2");	   // "2.日期调整"
		OLED_P8x16Str(28,3,".");
		OLED_P16x16Ch(36,3,9);
		OLED_P16x16Ch(52,3,10);
		OLED_P16x16Ch(68,3,7);
		OLED_P16x16Ch(84,3,8);

		OLED_P8x16Str(20,6,"3");	   // "3.温度调整"
		OLED_P8x16Str(28,6,".");
		OLED_P16x16Ch(36,6,16);
		OLED_P16x16Ch(52,6,17);
		OLED_P16x16Ch(68,6,7);
		OLED_P16x16Ch(84,6,8);
}
void ping2()
{
 		OLED_P8x16Str(20,0,"1");	   //“1.时间调整”
		OLED_P8x16Str(28,0,".");
		OLED_P16x16Ch(36,0,5);
		OLED_P16x16Ch(52,0,6);
		OLED_P16x16Ch(68,0,7);
		OLED_P16x16Ch(84,0,8);

 		OLED_P8x16Str(20,2,"2");	   //“2.整点报时”
		OLED_P8x16Str(28,2,".");
		OLED_P16x16Ch(36,2,8);
		OLED_P16x16Ch(52,2,20);
		OLED_P16x16Ch(68,2,21);
		OLED_P16x16Ch(84,2,5);

		OLED_P8x16Str(20,4,"3");	   //“3.闹钟”
		OLED_P8x16Str(28,4,".");
		OLED_P16x16Ch(36,4,22);
		OLED_P16x16Ch(52,4,23);

 		OLED_P8x16Str(20,6,"4");	   //“4.秒表”
		OLED_P8x16Str(28,6,".");
		OLED_P16x16Ch(36,6,24);
		OLED_P16x16Ch(52,6,25);
}