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

unsigned char Counter_Servo,Compare_Servo,Counter_Motor,Compare_Motor;
unsigned char key,speed,angle;
unsigned char i;

void main()
{
	Timer0_Init();
	Timer1_Init();
//	Timer2Init();
	while(1)
	{
		key=KEY_Scan(0);
		if(key==1){
			//if(angle==0){Compare_Servo=4;}
			if(angle==0){Compare_Servo=9;}
			if(angle==1){Compare_Servo=13;}
			if(angle==2){Compare_Servo=18;}
			if(angle==3){Compare_Servo=25;}
			angle++;
			angle%=4;
		}
		
		if(key==2){
			speed++;
			speed%=5;
			if(speed==0){Compare_Motor=0;}
			if(speed==1){Compare_Motor=30;}
			if(speed==2){Compare_Motor=50;}
			if(speed==3){Compare_Motor=75;}
			if(speed==4){Compare_Motor=100;}
		}
		if(key==3){
			while(KEY_Scan(0)!=2)
			{
				
				for(Compare_Servo=9;Compare_Servo<21;Compare_Servo++){
					delay_ms(1000);
				}
				for(Compare_Servo=21;Compare_Servo>10;Compare_Servo--){
					delay_ms(1000);
				}
								
			}
		}
	}
	
}

