#include <REGX52.H>
#include "delay.h"
#include "typedef.h"
#include "dht11.h"

u8  U8FLAG,k;
u8  U8count,U8temp;
u8  U8T_data_H,U8T_data_L,U8RH_data_H,U8RH_data_L,U8checkdata;
u8  U8T_data_H_temp,U8T_data_L_temp,U8RH_data_H_temp,U8RH_data_L_temp,U8checkdata_temp;
u8  U8comdata;
u8  count, count_r=0;

void  COM(void)
{
    unsigned char i;
    for(i=0;i<8;i++)	   
    {
  	    U8FLAG=2;
	   	while((!DATA)&&U8FLAG++);
		Delay_10us();
		Delay_10us();
		Delay_10us();
  		U8temp=0;
        if(DATA)U8temp=1;
		    U8FLAG=2;
		while((DATA)&&U8FLAG++);
	   	//��ʱ������forѭ��		  
	   	if(U8FLAG==1)break;
	   	//�ж�����λ��0����1	 
	   	   
		// ����ߵ�ƽ�߹�Ԥ��0�ߵ�ƽֵ������λΪ 1 
	   	 
		U8comdata<<=1;
	   	U8comdata|=U8temp;     
    }//rof
}

//--------------------------------
//-----��ʪ�ȶ�ȡ�ӳ��� ------------
//--------------------------------
//----���±�����Ϊȫ�ֱ���--------
//----�¶ȸ�8λ== U8T_data_H------
//----�¶ȵ�8λ== U8T_data_L------
//----ʪ�ȸ�8λ== U8RH_data_H-----
//----ʪ�ȵ�8λ== U8RH_data_L-----
//----У�� 8λ == U8checkdata-----
//----��������ӳ�������----------
//---- Delay();, Delay_10us();COM(); 
//--------------------------------
u8 DHT11_Start(void)
{
	//��������18ms 
    DATA=0;
	delay_ms(18);  //��ʱ18����
	DATA=1;
	//������������������ ������ʱ40us
	Delay_10us();
	Delay_10us();
	Delay_10us();
	Delay_10us();
	//������Ϊ���� �жϴӻ���Ӧ�ź� 
	DATA=1;
	//�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������	  
	if(!DATA)		 //T !	  
	{
	    U8FLAG=2;
	    //�жϴӻ��Ƿ񷢳� 80us �ĵ͵�ƽ��Ӧ�ź��Ƿ����	 
	    while((!DATA)&&U8FLAG++);
	    U8FLAG=2;
	    //�жϴӻ��Ƿ񷢳� 80us �ĸߵ�ƽ���緢����������ݽ���״̬
	    while((DATA)&&U8FLAG++);
	    //���ݽ���״̬		 
	    COM();
	    U8RH_data_H_temp=U8comdata;
	    COM();
	    U8RH_data_L_temp=U8comdata;
	    COM();
	    U8T_data_H_temp=U8comdata;
	    COM();
	    U8T_data_L_temp=U8comdata;
	    COM();
	    U8checkdata_temp=U8comdata;
	    DATA=1;
	    //����У�� 
	    U8temp=(U8T_data_H_temp+U8T_data_L_temp+U8RH_data_H_temp+U8RH_data_L_temp);
	    if(U8temp==U8checkdata_temp)
	    {
	   	   U8RH_data_H=U8RH_data_H_temp;//ʪ��������
	   	   U8RH_data_L=U8RH_data_L_temp;//ʪ��С��
	   	   U8T_data_H=U8T_data_H_temp;//�¶�����
	   	   U8T_data_L=U8T_data_L_temp;//�¶�С��
	   	   U8checkdata=U8checkdata_temp;//У��
	    }//fi
		return 1;
	}//fi
	else   //����������Ӧ
	{
	   return 0;
	}
	
}


