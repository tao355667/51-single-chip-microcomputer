/*
DS18B20�¶ȶ�ȡ
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��
#include "AM2301.h"//������1-wireЭ��
//#include "DS18B20.h"//DS18B20
//#include "AT24C02.h"//AT24C02

u8 TH,TL,HH,HL,PAR,PAR_CNT;
u16 T,T14,H;//�¶�ʪ��ֵ

f32 TrueT,TrueH;

void main()
{
	LCD_Init();//LCD��ʼ��
	delay_ms(2000);//��ʱ�������������ȶ��׶�
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"H:");
	
	while(1)
	{
		//ɨ������
		delay_ms(500);
		AM2301_Start();//��ʼ�ź�
		
		HH=AM2301_ReceiveByte();
		HL=AM2301_ReceiveByte();
		TH=AM2301_ReceiveByte();
		TL=AM2301_ReceiveByte();
		PAR=AM2301_ReceiveByte();
		
		H=((u16)HH<<8)|((u16)HL);
		T=((u16)TH<<8)|((u16)TL);
		PAR_CNT=HH+HL+TH+TL;//�������У��λ

		if(PAR_CNT==PAR){//ͨ��У������ʾ�¶�
			//��ʾ�¶�
			if(T/65535){
				LCD_ShowChar(1,3,'-');
			}else{LCD_ShowChar(1,3,'+');}
			T14=T&0x7FFF;
			LCD_ShowNum(1,4,T14/10,2);
			LCD_ShowChar(1,6,'.');
			LCD_ShowNum(1,7,T14%10,1);
			LCD_ShowChar(1,8,'C');
			//��ʾʪ��
			LCD_ShowNum(2,3,H/10,3);
			LCD_ShowChar(2,6,'.');
			LCD_ShowNum(2,7,H&10,1);
			LCD_ShowChar(2,8,'%');
		}
		
	}
}

