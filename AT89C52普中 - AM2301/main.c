/*
DS18B20温度读取
*/
#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "timer.h"//定时器
#include "AM2301.h"//单总线1-wire协议
//#include "DS18B20.h"//DS18B20
//#include "AT24C02.h"//AT24C02

u8 TH,TL,HH,HL,PAR,PAR_CNT;
u16 T,T14,H;//温度湿度值

f32 TrueT,TrueH;

void main()
{
	LCD_Init();//LCD初始化
	delay_ms(2000);//延时跳过传感器不稳定阶段
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"H:");
	
	while(1)
	{
		//扫描周期
		delay_ms(500);
		AM2301_Start();//开始信号
		
		HH=AM2301_ReceiveByte();
		HL=AM2301_ReceiveByte();
		TH=AM2301_ReceiveByte();
		TL=AM2301_ReceiveByte();
		PAR=AM2301_ReceiveByte();
		
		H=((u16)HH<<8)|((u16)HL);
		T=((u16)TH<<8)|((u16)TL);
		PAR_CNT=HH+HL+TH+TL;//计算出的校验位

		if(PAR_CNT==PAR){//通过校验再显示温度
			//显示温度
			if(T/65535){
				LCD_ShowChar(1,3,'-');
			}else{LCD_ShowChar(1,3,'+');}
			T14=T&0x7FFF;
			LCD_ShowNum(1,4,T14/10,2);
			LCD_ShowChar(1,6,'.');
			LCD_ShowNum(1,7,T14%10,1);
			LCD_ShowChar(1,8,'C');
			//显示湿度
			LCD_ShowNum(2,3,H/10,3);
			LCD_ShowChar(2,6,'.');
			LCD_ShowNum(2,7,H&10,1);
			LCD_ShowChar(2,8,'%');
		}
		
	}
}

