#ifndef DELAY_H
#define DELAY_H

//#define MAIN_Fosc		12000000L	//������ʱ��
#define MAIN_Fosc		11059200L	//������ʱ��

typedef unsigned char  u8;       /* defined for unsigned 8-bits integer variable 	  �޷���8λ���ͱ���  */
typedef signed   char  s8;       /* defined for signed 8-bits integer variable		  �з���8λ���ͱ���  */
typedef unsigned int   u16;      /* defined for unsigned 16-bits integer variable 	  �޷���16λ���ͱ��� */
typedef signed   int   s16;      /* defined for signed 16-bits integer variable 	  �з���16λ���ͱ��� */
typedef unsigned long  u32;      /* defined for unsigned 32-bits integer variable 	  �޷���32λ���ͱ��� */
typedef signed   long  s32;      /* defined for signed 32-bits integer variable 	  �з���32λ���ͱ��� */
typedef float          f32;      /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef double         f64;      /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */




void delay_ms(unsigned long int ms);


#endif
