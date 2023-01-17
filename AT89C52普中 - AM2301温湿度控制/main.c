/*
AM2301��ʪ�ȿ��ƣ���Ƭ��LED
*/
#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "key.h"//��������ͷ�ļ�
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "timer.h"//��ʱ��
#include "AM2301.h"//������1-wireЭ��
#include "AT24C02.h"//AT24C02

sbit fog=P2^2;			//��Ƭ
sbit cold=P2^3;			//����/����--��ŷ�
//sbit TOPLED=P2^4;		//�Ϸ�LED�����

u8 keynum,TH,TL,HH,HL,PAR=1,PAR_CNT=0;//����ֵ����ʪ�ȶ�ȡֵ��У��λ
u16 T,T14,H;//�¶�ʪ��ֵ
s8 HLow,HHigh,TLow,THigh;//8λ�з������ͣ���ʪ����ֵ
s32 TTrue;

void main()
{
	LCD_Init();
	delay_ms(2000);//��ʱ�������������ȶ��׶�
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"H:");
	
	HLow=AT24C02_ReadByte(0);
	HHigh=AT24C02_ReadByte(1);
	TLow=AT24C02_ReadByte(2);
	THigh=AT24C02_ReadByte(3);
	
	if(THigh>80 || TLow<-20 || THigh==TLow ){
		THigh=25;TLow=15;
	}
	if(HHigh>100 || HLow<0 || HHigh==HLow){
		HHigh=75;HLow=70;
	}
	
	LCD_ShowSignedNum(1,10,TLow,2);
	LCD_ShowSignedNum(1,14,THigh,2);
	LCD_ShowSignedNum(2,10,HLow,2);
	LCD_ShowSignedNum(2,14,HHigh,2);
	while(1)
	{
		delay_ms(300);
		keynum=KEY_Scan(1);
		
		/*��ȡ��ʪ��*/
		if(AM2301_Start()){//��ʼ�ź��յ�Ӧ��������Ϣ
			HH=AM2301_ReceiveByte();
			HL=AM2301_ReceiveByte();
			TH=AM2301_ReceiveByte();
			TL=AM2301_ReceiveByte();
			PAR=AM2301_ReceiveByte();
			H=((u16)HH<<8)|((u16)HL);
			T=((u16)TH<<8)|((u16)TL);
			PAR_CNT=HH+HL+TH+TL;//�������У��λ
		}
		/*��ʾ��ʪ��*/
		if(PAR_CNT==PAR){//ͨ��У������ʾ�¶�
			//��ʾ�¶�
			if(T/65535){
				TTrue=-(s16)(T&0x7FFF);
				LCD_ShowChar(1,3,'-');
			}else{
				TTrue=(s16)(T&0x7FFF);
			    LCD_ShowChar(1,3,'+');
			}
			T14=T&0x7FFF;
			LCD_ShowNum(1,4,T14/10,2);
			LCD_ShowChar(1,6,'.');
			LCD_ShowNum(1,7,T14%10,1);
			LCD_ShowChar(1,8,'C');
			//��ʾʪ��
			LCD_ShowNum(2,3,H/10,3);
			LCD_ShowChar(2,6,'.');
			LCD_ShowNum(2,7,H&10,1);
			LCD_ShowChar(2,8,'%');
		}
		/*�����ж�*/
		if(keynum){
			if(keynum==1){
				HLow--;
				if(HLow<0){HLow=0;}
			}
			if(keynum==2){
				HLow++;
				if(HLow>=HHigh){HLow--;}
			}
			if(keynum==3){
				HHigh--;
				if(HLow>=HHigh){HHigh++;}
			}
			if(keynum==4){
				HHigh++;
				if(HHigh>100){HHigh=100;}
			}
			if(keynum==5){
				TLow--;
				if(HLow<-20){HLow=-20;}
			}
			if(keynum==6){
				TLow++;
				if(TLow>=THigh){TLow--;}
			}
			if(keynum==7){
				THigh--;
				if(HLow>=HHigh){THigh++;}
			}
			if(keynum==8){
				THigh++;
				if(THigh>80){THigh=80;}
			}
			AT24C02_WriteByte(0,HLow);delay_ms(5);
			AT24C02_WriteByte(1,HHigh);delay_ms(5);
			AT24C02_WriteByte(2,TLow);delay_ms(5);
			AT24C02_WriteByte(3,THigh);delay_ms(5);
			
			LCD_ShowSignedNum(1,10,TLow,2);
			LCD_ShowSignedNum(1,14,THigh,2);
			LCD_ShowSignedNum(2,10,HLow,2);
			LCD_ShowSignedNum(2,14,HHigh,2);
		}
		/*�����ж�*/
		if(TTrue>THigh*10){
			LCD_ShowString(1,13,"*");
			cold=0;//�����¶�̫������
		}else if(TTrue<TLow*10){
			LCD_ShowString(1,9,"*");
			//cold=0;//�����¶�̫������
			cold=1;//�¶ȵ�������ر�����
		}else{
			LCD_ShowString(1,13," ");
			LCD_ShowString(1,9," ");
		}
		if(H>HHigh*10){
			LCD_ShowString(2,13,"*");
			fog=1;//ʪ��̫�߹ر���Ƭ
		}else if(H<HLow*10){
			LCD_ShowString(2,9,"*");
			fog=0;//ʪ��̫��������Ƭ
		}else{
			LCD_ShowString(2,13," ");
			LCD_ShowString(2,9," ");
		}
		
	}
}

