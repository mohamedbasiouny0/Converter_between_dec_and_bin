/*
 * KEYPSD.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mido kareem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dioo_int.h"
#include <avr/io.h>
#include <util/delay.h>
#include "KEYBAD.h"


u8 KPD_arr[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'n','0','=','+'}

};

void keybad_inti(void)
{
	MDIO_vidSetPortDirection(k_port,0x0f);
	MDIO_vidSetPortvalue(k_port,0xff);
	//HCLCD_vidSendString("WELCOME MOHAMED");
	//_delay_ms(500);
}

u8 keybad_PressKey(void)
{
	u8 pressed_key = NO_KEY ; //'O'
	for(u8 row=0;row<4;row++)
	{
		MDIO_vidSetPinValue(k_port,row,LOW);
		for(u8 col =0;col<4;col++)
		{       //MDIO_vidGetPinValue(k_port,(col+4),&buffer);
			if(MDIO_vidGetPinValue(k_port,(col+4))==0)//if(buffer==0)
			{
				pressed_key= KPD_arr[row][col];
			}
			while(MDIO_vidGetPinValue(k_port,col+4)==0){}
			_delay_ms(10);
		}

		MDIO_vidSetPinValue(k_port,row,HIGH);
	}
	return pressed_key;
}
