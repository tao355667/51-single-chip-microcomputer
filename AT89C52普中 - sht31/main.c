/*
DS18B20温度读取
*/
#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
//#include "timer.h"//定时器
#include "OneWire.h"//单总线1-wire协议
///#include "sht31.h"//sht31

u8 par;
u16 TH,TL,HH,HL;
u16 T,H;
u16 a;
void main()
{

	
	LCD_Init();
	//LCD_ShowString(1,1,"Hello");
	
	delay_ms(2000);
	
	while(1)
	{
		a=OneWire_Init();
		LCD_ShowNum(2,1,a,16);
		
		
		
		delay_ms(2000);
		
		
		
//		a=OneWire_Init();
//		TH=OneWire_ReceiveByte();
//		TL=OneWire_ReceiveByte();
//		HH=OneWire_ReceiveByte();
//		HL=OneWire_ReceiveByte();
//		par=OneWire_ReceiveByte();
//		T=((TH<<8)|TL)&0x7F;
//		H=(HH<<8)|HL;
		
//		T=OneWire_Receive2Byte();
//		H=OneWire_Receive2Byte();
//		par=OneWire_ReceiveByte();
//		LCD_ShowBinNum(1,1,TH<<8,16);
//		LCD_ShowBinNum(2,1,TL,16);
//		LCD_ShowBinNum(1,1,TH<<8,16);
//		LCD_ShowBinNum(2,1,TL,16);
//		delay_ms(1000);
//		LCD_ShowNum(1,1,T,16);
//		LCD_ShowNum(2,1,par,16);
//		delay_ms(1000);
		
	}
	
}

