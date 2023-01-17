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

float T;

void main()
{
	DS18B20_ConvertT();//����һ������ʱ����ʱһ�ᣬ��һ��ת���õ�׼ȷֵ
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

