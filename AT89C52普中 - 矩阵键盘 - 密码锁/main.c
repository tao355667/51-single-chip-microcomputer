/*
密码锁
默认密码为2345
*/
#include <REGX52.H>//标准头文件
#include "51common.h"//定义unsigned char为u8,延时函数delay_ms()
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "MatrixKey.h"//矩阵按键

u8 key,count;
u16 Password;

void main()
{
	
	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowNum(2,1,Password,4);
	while(1)
	{
		key=MatrixKeyDown();
		if(key){
			if(key<=10){//如果按键是S1~S10,
				if(count<4){
					Password *= 10;//密码左移一位
					Password += key%10;//密码新的一位
				}
				count++;
				
			}
			LCD_ShowNum(2,1,Password,4);
			
			if(key==11){//如果按键是S11,确认
				if(Password==2345){
					LCD_ShowString(1,14,"OK ");
					count=0;//次数清零
					Password=0;//密码清零
					LCD_ShowString(2,1,"   ");//重置显示数字
				}else{
					LCD_ShowString(1,14,"ERR");
				}
				
			}
			
			if(key==12){//如果按键是S12,取消
				count=0;//次数清零
				Password=0;//密码清零
				LCD_ShowNum(2,1,Password,4);//重置显示
				LCD_ShowString(1,14,"   ");
			}
			LCD_ShowNum(2,1,Password,4);
		}
	}
}

