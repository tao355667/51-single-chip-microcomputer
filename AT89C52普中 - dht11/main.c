#include <REGX52.H>//自带头文件
#include "typedef.h"//定义unsigned char为u8
#include "delay.h"//延时头文件，可调用delay_ms()
#include "key.h"//按键头文件，用于修改时间
#include "LCD1602.h"//LCD1602头文件
#include "dht11.h"
extern unsigned char U8RH_data_H;
extern unsigned char U8T_data_H;
extern unsigned char U8RH_data_L;
extern unsigned char U8T_data_L;
void main()
{
//	u8 s=20;
//	LCD_Init();
//	LCD_ShowChar(1,1,'2');
//	LCD_ShowString(1,2,"T:");
//	LCD_ShowNum(1,4,s,3);
//	LCD_ShowSignedNum(1,8,-56,2);
//	LCD_ShowHexNum(2,1,0x3f,3);
//	LCD_ShowBinNum(2,5,0xe,4);
//	

	u8 humidity_H,humidity_L,temperature_H,temperature_L;

	LCD_Init();
	LCD_ShowString(1,1,"Tem:");
	LCD_ShowString(1,9,"Hum:");
	do
	{
		DHT11_Start();
		delay_ms(100);
	}while(U8RH_data_H==0&&U8T_data_H==0);
		
	while(1)
	{
		DHT11_Start();
			 
		//读出温湿度，只取整数部分
      	humidity_H = U8RH_data_H;
      	temperature_H = U8T_data_H;
		humidity_L = U8RH_data_L;
      	temperature_L = U8T_data_L;
			 
//		LCD_ShowNum(1,1,temperature/10+0x30,2);
//		LCD_ShowNum(1,8,temperature%10+0x30,3);
//		LCD_ShowNum(2,1,humidity/10+0x30,3);
//		LCD_ShowNum(2,8,humidity%10+0x30,3);
		
		LCD_ShowNum(2,1,temperature_H,2);
		LCD_ShowChar(2,3,'.');
		LCD_ShowNum(2,4,temperature_L,2); 
		LCD_ShowString(2,5,"°");
		LCD_ShowChar(2,6,'C');
		LCD_ShowNum(2,9,humidity_H,2);
		LCD_ShowChar(2,11,'.');
		LCD_ShowNum(2,12,humidity_L,2);
		LCD_ShowString(2,11,"%");
		delay_ms(100);
	}
}

