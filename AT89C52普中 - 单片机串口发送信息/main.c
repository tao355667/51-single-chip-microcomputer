/*
��������Է�������
UART(Universal Asynchronous Receiver Transmitter)
TXD(transmit exchange data)
RXD(receive exchange data)
���ڳ��õ�ƽ��׼
TTL��ƽ��+5V��ʾ1��0V��ʾ0
RS232��ƽ��-3~-15V��ʾ1��+3~+15V��ʾ0
RS485��ƽ������ѹ��+2~+6V��ʾ1��-2V~-6V��ʾ0

*/
#include <REGX52.H>
#include <delay.h>
#include <key.h>

unsigned char sec;

void Uart_Init(void)		//9600bps@11.0592MHz
{
	
	SCON=0x40;
	PCON|=0x00;
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFD;		//�趨��ʱ��ֵ
	TH1 = 0xFD;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	
}
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
	
}

void main()
{
	Uart_Init();
	
	while(1)
	{
		UART_SendByte(sec++);
		P2=0xf0;delay_ms(500);
		P2=0x0f;delay_ms(500);
	}
}

