/*
��ʱ�����
SG90���һ������20ms
�ߵ�ƽʱ���Ӧ�Ƕ�
0.5ms	0��
1ms		45��
1.5ms	90��
2ms		135��
2.5ms	180��
//��������Ӧ������Ϊ�����˴��������£�
			if(speed==0){Compare_Servo=4;}
			if(speed==1){Compare_Servo=8;}
			if(speed==2){Compare_Servo=13;}
			if(speed==3){Compare_Servo=18;}
			if(speed==4){Compare_Servo=25;}
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "51common.h"//����unsigned charΪu8,��ʱ����delay_ms()
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��
#include "delay.h"//��ʱ����



void main()
{

	
//	
//	
//	P2=0x00;
//	for(i=0;i<255;i++){
//		P2++;
//		delay_ms(100);
//	}
//	
	Timer2_Init();
	
	while(1)
	{
		
	}
	
}

