#ifndef __LCD1602_H__
#define __LCD1602_H__


//用户调用函数：
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
//	u8 s=20;
//	LCD_Init();
//	LCD_ShowChar(1,1,'2');
//	LCD_ShowString(1,2,"T:");
//	LCD_ShowNum(1,4,s,3);
//	LCD_ShowSignedNum(1,8,-56,2);
//	LCD_ShowHexNum(2,1,0x3f,3);
//	LCD_ShowBinNum(2,5,0xe,4);
	
#endif
