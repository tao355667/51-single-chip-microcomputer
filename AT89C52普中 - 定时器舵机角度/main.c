/*
��ʱ�����
SG90���һ������20ms
�ߵ�ƽʱ���Ӧ�Ƕ�
0.5ms	0��
1ms		45��
1.5ms	90��
2ms		135��
2.5ms	180��
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "51common.h"//����unsigned charΪu8,��ʱ����delay_ms()
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��

unsigned char Counter,Compare;
unsigned char key,speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		key=KEY_Scan(0);
		if(key==1){
			speed++;
			speed%=5;
			if(speed==0){Compare=5;}
			if(speed==1){Compare=10;}
			if(speed==2){Compare=15;}
			if(speed==3){Compare=20;}
			if(speed==4){Compare=25;}
		}
	}
	
}

