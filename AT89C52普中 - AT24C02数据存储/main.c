/*
AT24C02���ݴ洢
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��
#include "I2C.h"//I2C(iic)ͨ��Э��
#include "AT24C02.h"//AT24C02�洢��

u8 a=156;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Hello");
	AT24C02_WriteByte(1,15);//���ַ(0-255)��������6
	delay_ms(5);
	a=AT24C02_ReadByte(1);//��ȡ��ַ1������
	LCD_ShowNum(2,1,a,3);
	
	
	while(1)
	{
		
	}
	
}

