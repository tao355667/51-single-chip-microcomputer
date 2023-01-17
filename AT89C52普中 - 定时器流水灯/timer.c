#include <REGX52.H>
#include "51common.h"

void Timer0_Init()
{
//	TMOD=0x01;//����ģʽ
	TMOD&=0xF0;//����ģʽ
	TMOD|=0x01;//����ģʽ
	TF0=0;//���λ����0
	TR0=1;//��ʼ����
	//��ʱ1ms��ֵ
	TH0=64535/256;
	TL0=64535%256;
	//����T0�ж�
	EA=1;ET0=1;
	//�ж����ȼ�
	PT0=0;
}

u16 T0count;
void Timer0_Rountine() interrupt 1
{
	//��ʱ1ms��ֵ
	TH0=64535/256;
	TL0=64535%256;
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		P2=~P2;
	}
	

}
