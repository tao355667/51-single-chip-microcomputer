/*
DS18B20�¶ȶ�ȡ
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
//#include "timer.h"//��ʱ��
#include "OneWire.h"//������1-wireЭ��
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

