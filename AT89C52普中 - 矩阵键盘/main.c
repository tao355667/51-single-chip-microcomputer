/*
�̰���������ϵİ�����LCD����ʾ��Ӧ�������
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "51common.h"//����unsigned charΪu8,��ʱ����delay_ms()
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�


void main()
{
	u8 key;
	LCD_Init();
	
	while(1)
	{
		key=MatrixKeyDown();
		if(key!=0){LCD_ShowNum(1,1,key,2);}
	}
}



//void key_scan(void)
//{
//	if(!keyMode){
//		delay_ms(10);
//		while(!keyMode);
//		mode=(mode+1)%4;
//	}
//	
//}


