/*
��ʱ����ˮ��ʾ��
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
			if(speed==0){Compare=0;}
			if(speed==1){Compare=25;}
			if(speed==2){Compare=50;}
			if(speed==3){Compare=75;}
			if(speed==3){Compare=100;}
		}
	}
	
}

