/*
�˳�������ʱ�ķ���������һ�������ӣ��������ֶ�����ʱ��
���裺LCD1602����������������������

ʹ�÷���������ʱΪģʽ0����0ʱ�̿�ʼ��ʱ��
		  �������ü���1�룩���ɽ�������ģʽ1��������ģʽ1�п�ͨ���Ӽ��������������ֵ
		  �ٰ����ü����ɽ�������ģʽ1��������ģʽ1�п�ͨ���Ӽ��������ڡ��롱����ֵ
		  �ٰ����ü����ɽ�������ģʽ2��������ģʽ2�п�ͨ���Ӽ��������ڡ��֡�����ֵ
		  �ٰ����ü����ɽ�������ģʽ3��������ģʽ3�п�ͨ���Ӽ��������ڡ�ʱ������ֵ
		  �ٰ����ü����ص�ģʽ0��ʱ��ģʽ��

*/

#include <REGX52.H>//��׼ͷ�ļ�
#include "typedef.h"//����unsigned charΪu8
#include "delay.h"//��ʱͷ�ļ����ɵ���delay_ms()
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�

#define keyMode P3_1	//ģʽ����
#define keyPlus P3_0    //�Ӽ�
#define keyReduce P3_2  //����

void showTime(void);//ʱ��+1s����ʾʱ��
void set_second(void);//������
void set_minute(void);//���÷���
void set_hour(void);//����Сʱ
void key_scan(void);//ɨ�����ü�

//��ʼʱ��--ȫ�ֱ���
u8 second=0;//��
u8 minute=0;//��
u8 hour=0;//ʱ
u8 mode=0;//��ʼģʽ

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"TIME:");//LCD��Ļ����ʾTIME��
	LCD_ShowChar(2,3,':');//��ʾʱ���м��ð��
	LCD_ShowChar(2,6,':');//��ʾʱ���м��ð��
	
	while(1)
	{
		key_scan();//������ð����Ƿ���
		if(mode==0)showTime();//��ʾʱ��
		if(mode==1)set_second();//������
		if(mode==2)set_minute();//���÷�
		if(mode==3)set_hour();//����Сʱ
		LCD_ShowString(1,6,"           ");//�������ֺۼ�
	}
}



void key_scan(void)
{
	if(!keyMode){
		delay_ms(10);
		while(!keyMode);
		mode=(mode+1)%4;
	}
	
}

void showTime(void)
{
	//��ʱ������Ĵ���
	if(second>59){
		second=0;minute++;
	}
	if(minute>59){
		minute=0;hour++;
	}
	if(hour>23){
		hour=0;
	}
	LCD_ShowNum(2,1,hour,2);//��ʾʱ
	LCD_ShowNum(2,4,minute,2);//��ʾ��
	LCD_ShowNum(2,7,second++,2);//��ʾ��
	delay_ms(980);//��ʱ��������1�룬������������ִ��ʱ�䣬���ʵ���С
}

void set_second(void)
{
	LCD_ShowString(1,6,"Set:Second ");//��ʾ����ģʽʾ������
    do{
		if(!keyPlus){//������⣬�����̰�����Ч�����ڵ���
			second=(second+1)%60;//������Чһ�Σ�����+1��Ϊ��ֹ���ʹ����ȡ�����㷨
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		if(!keyReduce){
			(second==0)?(second=59):(second--);//�ʺű��ʽ��������Чһ�Σ�����-1�������¸�ֵ��ֹ���
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		LCD_ShowNum(2,7,second,2);//չʾ���ں������
	}while(keyMode);//ģʽ����û���£���һֱѭ����ģʽ��������ʱ��������ģʽ
}

void set_minute(void)
{
	LCD_ShowString(1,6,"Set:Minute  ");//��ʾ����ģʽʾ������
	do{
		if(!keyPlus){
			 minute=(minute+1)%60;
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		if(!keyReduce){
			(minute==0)?(minute=59):(minute--);
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		LCD_ShowNum(2,4,minute,2);
	}while(keyMode);
}

void set_hour(void)
{
	LCD_ShowString(1,6,"Set:Hour   ");//��ʾ����ģʽʾ������
	do{
		if(!keyPlus){
			hour=(hour+1)%24;
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		if(!keyReduce){
			(hour==0)?(hour=23):(hour--);
			delay_ms(200);//��ʱ�Լ���ʱ������ٶ�
		}
		LCD_ShowNum(2,1,hour,2);
	}while(keyMode);
}
