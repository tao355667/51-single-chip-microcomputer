/*
DS18B20温度读取
*/
#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "timer.h"//定时器
#include "OneWire.h"//单总线1-wire协议
#include "DS18B20.h"//DS18B20

float T;

void main()
{
	DS18B20_ConvertT();//读第一个数的时候延时一会，第一次转换得到准确值
	delay_ms(1000);
	
	LCD_Init();
	LCD_ShowString(1,1,"Hello");
	
	while(1)
	{
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if(T<0){
			LCD_ShowChar(2,1,'-');
			T=-T;
		}else{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,T,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);

		
	}
	
}

