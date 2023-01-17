/*
DS18B20�¶ȶ�ȡ
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��
#include "OneWire.h"//������1-wireЭ��
#include "DS18B20.h"//DS18B20
#include "AT24C02.h"//AT24C02

f32 T,TShow;//�¶�ֵ
char TLow,THigh;//�¶ȼ���ֵ
u8 KeyNum=0;

void main()
{
	THigh=AT24C02_ReadByte(0);
	TLow=AT24C02_ReadByte(1);
	if(THigh>125 || TLow<-55 || THigh==TLow){
		THigh=25;
		TLow=15;
	}
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,THigh,3);
	LCD_ShowSignedNum(2,12,TLow,3);
	
	DS18B20_ConvertT();
	delay_ms(1000);
	
	while(1)
	{
		KeyNum=KEY_Scan(1);
		/*�¶ȶ�ȡ����ʾ*/
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if(T<0){
			LCD_ShowChar(1,3,'-');
			TShow=-T;
		}else{
			LCD_ShowChar(1,3,'+');
			TShow=T;
		}
		LCD_ShowNum(1,4,TShow,3);
		LCD_ShowChar(1,7,'.');
		LCD_ShowNum(1,8,(u32)(TShow*10000)%10000,4);
		
		/*��ֵ�жϼ���ʾ*/
		if(KeyNum){
			if(KeyNum==1){
				THigh++;
				if(THigh>125){THigh=125;}
			}
			if(KeyNum==2){
				THigh--;
				if(THigh<=TLow){THigh++;}
			}
			if(KeyNum==3){
				TLow++;
				if(TLow>=THigh){TLow--;}
			}
			if(KeyNum==4){
				TLow--;
				if(TLow<-55){TLow=-55;}
			}
			LCD_ShowSignedNum(2,4,THigh,3);
			LCD_ShowSignedNum(2,12,TLow,3);
			AT24C02_WriteByte(0,THigh);
			delay_ms(5);
			AT24C02_WriteByte(1,TLow);
			delay_ms(5);
		}
		if(T>THigh){
			LCD_ShowString(1,13,"OV:H");
		}else if(T<TLow){
			LCD_ShowString(1,13,"OV:L");
		}else{
			LCD_ShowString(1,13,"    ");
		}
		
		
	}
	
}

