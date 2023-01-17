/*
短按矩阵键盘上的按键，LCD上显示对应按键编号
*/
#include <REGX52.H>//标准头文件
#include "51common.h"//定义unsigned char为u8,延时函数delay_ms()
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件


void main()
{
	u8 key;
	LCD_Init();
	
	while(1)
	{
		key=MatrixKeyDown();
		if(key!=0){LCD_ShowNum(1,1,key,2);}
	}
}



//void key_scan(void)
//{
//	if(!keyMode){
//		delay_ms(10);
//		while(!keyMode);
//		mode=(mode+1)%4;
//	}
//	
//}


