#include <REGX52.H>
#include <INTRINS.H>
#include "delay.h"
#include "key.h"

u8 key;
void main()
{
//	P2=0xfe;//1111 1110
	
	//P2_0 = 1;
	while(1)
	{
		key=KEY_Scan(1);
		if(key)
		{
			switch(key)
			{
				case KEY1_PRES:
					P2_0 = !P2_0;break;
				case KEY2_PRES:
					P2_1 = 0;break;
				case KEY3_PRES:
					P2=P2>>1;break;
				case KEY4_PRES:
					P2=P2<<1;break;
			}
		}else{
			if(KEY2==1) P2_1 = 1;
			delay_ms(20);
		}
		delay_ms(10);
		
	}
}

