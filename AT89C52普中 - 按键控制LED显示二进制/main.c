#include <REGX52.H>
#include <INTRINS.H>

typedef unsigned char u8;

void delay_ms(unsigned long int ms);		//@12.000MHz


void main()
{
	u8 LEDNum=0;//�洢Ҫ��ʾ�Ķ�������
	while(1)
	{
		if(P3_1==0){
			delay_ms(20);
			while(P3_1==0);

			delay_ms(20);
			//P2��λֵ1111 1111
			P2=~++LEDNum;//���洢�Ķ�������ת��ΪP2��Ҫ��ĸ�ʽ

		}
	}
}

void delay_ms(unsigned long int ms)		//@12.000MHz
{
	unsigned char i, j;
    while(ms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
    }
}
