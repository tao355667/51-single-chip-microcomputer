/*
AT24C02数据存储
*/
#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "timer.h"//定时器
#include "I2C.h"//I2C(iic)通信协议
#include "AT24C02.h"//AT24C02存储器

u8 a=156;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Hello");
	AT24C02_WriteByte(1,15);//向地址(0-255)存入数据6
	delay_ms(5);
	a=AT24C02_ReadByte(1);//读取地址1的数据
	LCD_ShowNum(2,1,a,3);
	
	
	while(1)
	{
		
	}
	
}

