/*
������
Ĭ������Ϊ2345
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "51common.h"//����unsigned charΪu8,��ʱ����delay_ms()
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "MatrixKey.h"//���󰴼�

u8 key,count;
u16 Password;

void main()
{
	
	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowNum(2,1,Password,4);
	while(1)
	{
		key=MatrixKeyDown();
		if(key){
			if(key<=10){//���������S1~S10,
				if(count<4){
					Password *= 10;//��������һλ
					Password += key%10;//�����µ�һλ
				}
				count++;
				
			}
			LCD_ShowNum(2,1,Password,4);
			
			if(key==11){//���������S11,ȷ��
				if(Password==2345){
					LCD_ShowString(1,14,"OK ");
					count=0;//��������
					Password=0;//��������
					LCD_ShowString(2,1,"   ");//������ʾ����
				}else{
					LCD_ShowString(1,14,"ERR");
				}
				
			}
			
			if(key==12){//���������S12,ȡ��
				count=0;//��������
				Password=0;//��������
				LCD_ShowNum(2,1,Password,4);//������ʾ
				LCD_ShowString(1,14,"   ");
			}
			LCD_ShowNum(2,1,Password,4);
		}
	}
}

