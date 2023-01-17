#include <REGX52.H>
#include "key.h"


sbit Motor=P1^0;

unsigned char Counter_Motor=0,Compare_Motor=50;
unsigned char i;

void Timer2_Init(void)		//50����@11.0592MHz
{
	T2MOD = 0x00;		//��ʼ��ģʽ�Ĵ���
	T2CON = 0x04;		//��ʼ�����ƼĴ�����16λ�Զ���װ��
	TL2 = 0x00;		//���ö�ʱ��ֵ
	TH2 = 0x4C;		//���ö�ʱ��ֵ
	RCAP2L = 0x00;		//���ö�ʱ����ֵ
	RCAP2H = 0x4C;		//���ö�ʱ����ֵ
	
	EA=1;ET2=1;//ʹ���ж�
	
	TR2 = 1;		//��ʱ��2��ʼ��ʱ
	
}


void Timer2_Rountine() interrupt 5
{
//	P2=0x00;
//	//	P2=0x00;
//	
//	for(i=0;i<255;i++){
//		P2++;
//		delay_ms(100);
//	}
//	
	Counter_Motor++;
	Counter_Motor%=100;
	
	if(Counter_Motor>Compare_Motor)
	{
		Motor=1;
		P2=0x0F;
	}else{
		Motor=0;
		P2=0xF0;
	}

}
