/*
 * LCD.c
 *
 *  Created on: Aug 19, 2023
 *      Author: WIN 10 PRO
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dioo_int.h"

#include "LCD.h"
#include "util/delay.h"




void HCLCD_vidInit(void)
{
	MDIO_vidSetPortDirection(lcd_data_port,0xff);
	MDIO_vidSetPinDirection(lcd_ctrl_port,lcd_en_pin,OUTPUT);
	MDIO_vidSetPinDirection(lcd_ctrl_port,lcd_rs_pin,OUTPUT);
	_delay_ms(50);
	HCLCD_vidSendCommand(0b00111000);
	_delay_ms(1);
	HCLCD_vidSendCommand(0b00001100);
	_delay_ms(1);
	HCLCD_vidSendCommand(0b00000001);
	_delay_ms(3);
	HCLCD_vidSendCommand(0b00000110);
	_delay_ms(1);




}
void HCLCD_vidSendCommand(u8 cpy_u8Command)
{
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_rs_pin,LOW);
	MDIO_vidSetPortvalue(lcd_data_port,cpy_u8Command);
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_en_pin,HIGH);
	_delay_ms(1);
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_en_pin,LOW);
	_delay_ms(1);
}
void HCLCD_vidSendData(u8 cpy_u8Data)
{
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_rs_pin,HIGH);
	MDIO_vidSetPortvalue(lcd_data_port,cpy_u8Data);
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_en_pin,HIGH);
	_delay_ms(1);
	MDIO_vidSetPinValue(lcd_ctrl_port,lcd_en_pin,LOW);
	_delay_ms(1);
}
void HCLCD_vidSendString(const u8* add_pu8String)
{
    for(u8 i=0;add_pu8String[i];i++)
    {
    	HCLCD_vidSendData(add_pu8String[i]);
    }
}
void HCLCD_vidSendNumber(s32 cpy_u32Number) //123
{      u32 cpy_u32power=1;
       s32 cpy_u32num=cpy_u32Number;
      if(cpy_u32Number==0)
      {
    	  HCLCD_vidSendData('0');
    	  return;
      }
      if(cpy_u32Number<0)
      {

    	  cpy_u32Number=cpy_u32Number*(-1);
    	  HCLCD_vidSendData('-');
      }
      while(cpy_u32num)
      {//01234

    	  cpy_u32num=cpy_u32num/10;          //01234  0123  012   01   0 0
    	  cpy_u32power=cpy_u32power*10;      //10000
      }
      cpy_u32power=cpy_u32power/10;
      while(cpy_u32power>0)
      {
    	  cpy_u32num=cpy_u32Number/cpy_u32power;  //01234/1000=0
    	  cpy_u32Number%=cpy_u32power;
    	  cpy_u32power/=10;

    	  HCLCD_vidSendData(cpy_u32num+'0');
      }




}

void HCLCD_vidSendFloat(f64 cpy_f64Float) //3.14 *1000 3140
{
	  u32 cpy_u32power=1;
	       s32 cpy_u32num=cpy_f64Float;
	       s32 i=0;

	      if(cpy_f64Float==0)
	      {
	    	  HCLCD_vidSendData('0');
	    	  return;
	      }
	      if(cpy_f64Float<0)
	      {

	    	  cpy_f64Float=cpy_f64Float*(-1);
	    	  HCLCD_vidSendData('-');
	      }
	      while(cpy_u32num)//1234
	      {

	    	  cpy_u32num=cpy_u32num/10;
	    	   i++;//4
	    	  cpy_u32power=cpy_u32power*10;      //10000
	      }
	      s32 int_num=cpy_f64Float*10000;  //1234.1234-->12341234
	      cpy_u32power=cpy_u32power*1000;
	      while(cpy_u32power>0)
	      {
	    	  cpy_u32num=int_num/cpy_u32power;  //01234/1000=0
	    	  int_num%=cpy_u32power;
	    	  cpy_u32power/=10;
               if(i==0)
               {
            	   HCLCD_vidSendData('.');

               }
               i--;
	    	  HCLCD_vidSendData(cpy_u32num+'0');
	      }




	/*
	HCLCD_vidSendNumber((s32)cpy_f64Float); //3
	HCLCD_vidSendData('.');//3.
	cpy_f64Float-=(s32)cpy_f64Float;//.14
	while(cpy_f64Float)//0.14*100
	{
		cpy_f64Float*=10;//1.4   4
		HCLCD_vidSendData((s32)cpy_f64Float+'0');//'1'   4
		cpy_f64Float-=(s32)cpy_f64Float;//0.4    0

	}
*/

}
void HCLCD_vidGoTo(u8 cpy_u8X, u8 cpy_u8Y)
{
    if(cpy_u8X==0)
    {
    	HCLCD_vidSendCommand(0x80|cpy_u8Y);
    }
    if(cpy_u8X==1)
    {
    	HCLCD_vidSendCommand(0x80+0x40+cpy_u8Y);
    }
}
void HCLCD_vidClear(void)
{
	HCLCD_vidSendCommand(0b00000001);
	_delay_ms(1);
}
void HCLCD_vidSendSpecialChar(const u8* arr_u8Char, u8 cpy_u8BlockNumber)
{
	HCLCD_vidSendCommand(0x40+(cpy_u8BlockNumber*8));  //CGRAM
			for(u8 i=0;i<8;i++)
			{
				HCLCD_vidSendData(arr_u8Char[i]);

			}
	         HCLCD_vidSendCommand(0x80);  //DDRAM
}
