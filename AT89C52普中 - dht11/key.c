#include "key.h"
#include "typedef.h"
#include "delay.h"

u8 KEY_Scan(u8 mode)//����ģʽ��0Ϊ�㰴��1Ϊ����
{
	static u8 key_up=1;//�����ɿ�Ϊ1
	if(mode)key_up=1;
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_ms(10);
		key_up=0;
		
		if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(KEY3==0)return KEY3_PRES;
		else if(KEY4==0)return KEY4_PRES;
		
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1) key_up=1;
	return 0;//�ް�������
	
	
}




