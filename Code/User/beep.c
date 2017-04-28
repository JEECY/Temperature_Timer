#include "beep.h"
uchar WD4,WD5,WD6; 
//--------------
//   高温报警
//--------------
void BJ_DS18B20()	  //延时太长
{
	if(((WD4>=2)&&(WD5>=8)&&(WD6>=0))||(WD4>=4))
	{
		beep=0;
		delay(3000);
		beep=1;
		delay(3000);
	}

	else
	beep=1;

}			
void BS()
{
	uchar i;
	for(i=0;i<10;i++)
	{
		yellow=0;
		beep=0;
		delay(2000);
		yellow=1;
		beep=1;
		delay(2000);
	}
}