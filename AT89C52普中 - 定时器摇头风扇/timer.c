#include <REGX52.H>
#include "key.h"

sbit LED=P2^0;
sbit Motor=P1^0;
sbit Servo=P0^0;


extern unsigned char Counter_Motor,Counter_Servo,Compare_Servo,Compare_Motor;
extern unsigned char key;

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
	PT0=1;
}

void Timer1_Init()
{
//	TMOD=0x01;//����ģʽ
	TMOD&=0x0F;//����ģʽ--��������λ������λ����
	TMOD|=0x10;//����ģʽ--��������λ���������ݸ��µ���λ��
	TF1=0;//���λ����0
	TR1=1;//��ʼ����
	//��ʱ0.1ms��ֵ
	TH1=0xFF;
	TL1=0xA4;
	//����T0�ж�
	EA=1;ET1=1;
	//�ж����ȼ�
	PT1=0;
}

void Timer2Init(void)		//10΢��@11.0592MHz
{
	T2MOD = 0;		//��ʼ��ģʽ�Ĵ���
	T2CON = 0;		//��ʼ�����ƼĴ���
	TL2 = 0xF7;		//���ö�ʱ��ֵ
	TH2 = 0xFF;		//���ö�ʱ��ֵ
	RCAP2L = 0xF7;		//���ö�ʱ����ֵ
	RCAP2H = 0xFF;		//���ö�ʱ����ֵ
	TR2 = 1;		//��ʱ��2��ʼ��ʱ
}


void Timer0_Rountine() interrupt 1
{
	//��ʱ0.1ms��ֵ
	TH0=0xFF;
	TL0=0xA4;
	Counter_Servo++;
	Counter_Servo%=200;
	if(Counter_Servo<Compare_Servo)
	{
		LED=0;
		Servo=1;
	}else{
		LED=1;
		Servo=0;
	}
	
}

void Timer1_Rountine() interrupt 3
{
	
	//��ʱ0.1ms��ֵ
	TH1=0xFF;
	TL1=0xA4;
	Counter_Motor++;
	Counter_Motor%=100;
	if(Counter_Motor<Compare_Motor)
	{
		Motor=1;
	}else{
		Motor=0;
	}
	
}

void Timer2_Rountine() interrupt 5
{
	TL2 = 0xF7;		//���ö�ʱ��ֵ
	TH2 = 0xFF;		//���ö�ʱ��ֵ
	key=KEY_Scan(1);
}
