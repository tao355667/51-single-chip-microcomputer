#ifndef KEY_H
#define KEY_H
#include <REGX52.H>
#include "delay.h"//delay_ms()   unsigned charΪu8,

#define KEY1 P3_1//������ӳ������
#define KEY2 P3_0
#define KEY3 P3_2
#define KEY4 P3_3

#define KEY1_PRES 1
#define KEY2_PRES 2
#define KEY3_PRES 3
#define KEY4_PRES 4

u8 KEY_Scan(u8 mode);

#endif
