#include <REGX52.H>
#include "51common.h"

sbit LED=P2^0;
sbit Motor=P1^0;

extern unsigned char Counter,Compare;

void Timer0_Init()
{
//	TMOD=0x01;//����ģʽ
	TMOD&=0xF0;//����ģʽ--��������λ������λ����
	TMOD|=0x01;//����ģʽ--��������λ���������ݸ��µ���λ��
	TF0=0;//���λ����0
	TR0=1;//��ʼ����
	//��ʱ0.1ms��ֵ
	TH0=0xFF;
	TL0=0xA4;
	//����T0�ж�
	EA=1;ET0=1;
	//�ж����ȼ�
	PT0=0;
}


void Timer0_Rountine() interrupt 1
{
	//��ʱ0.1ms��ֵ
	TH0=0xFF;
	TL0=0xA4;
	Counter++;
	Counter%=200;
	if(Counter<Compare)
	{
		LED=0;
		Motor=1;
	}else{
		LED=1;
		Motor=0;
	}
	
	

}
