
/*
 * test.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Moahmed Basiouny
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYBAD.h"
#include "LCD.h"
#include "dioo_int.h"
#include <util/delay.h>

int main()
{
	u8 key;
	u8 i = 0;
	u32 num1 = 0;
	u32 x ;
	u8 k ;
	u8 j = 0;
	HCLCD_vidInit();
	keybad_inti();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("WELCOME MOHAMED");
	_delay_ms(1500);
	HCLCD_vidClear();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("* dec to bin ");
	HCLCD_vidGoTo(1,0);
	HCLCD_vidSendString("/ bin to dec ");
	_delay_ms(1500);
	HCLCD_vidClear();
	while(1)
	{
		key=keybad_PressKey();
		if(key!=NO_KEY)
		{
			if(key>='0'&&key<='9')
			{
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				num1=num1*10+(key -'0');
				i++;

			}
			if(key=='*')
			{
				x = 0;
				while (num1!=0)
				{
					if (num1 >= 512)
					{
						num1-=512;
						x+=1000000000;
					}
					if (num1 >= 256)
					{
						num1-=256;
						x+=100000000;
					}
					if (num1 >= 128)
					{
						num1-=128;
						x+=10000000;
					}
					if (num1 >= 64)
					{
						num1-=64;
						x+=1000000;
					}
					if (num1 >= 32)
					{
						num1-=32;
						x+=100000;
					}
					if (num1 >= 16)
					{
						num1-=16;
						x+=10000;
					}
					if (num1 >= 8)
					{
						num1-=8;
						x+=1000;
					}
					if (num1 >= 4)
					{
						num1-=4;
						x+=100;
					}
					if (num1 >= 2)
					{
						num1-=2;
						x+=10;
					}
					if (num1 >= 1)
					{
						num1-=1;
						x+=1;
					}
				}
				HCLCD_vidGoTo(1,0);
				HCLCD_vidSendNumber(x);
			}
			if(key =='/')
			{
				x = 0;
				HCLCD_vidGoTo(1,0);

				if(num1%10>1)
				{
					HCLCD_vidSendString("ENTER A BIN NUM");
					_delay_ms(2000);
					HCLCD_vidClear();
					num1=0;
					i=0;
				}
				else if (num1%10==1 || num1%10==0)
				{
					while(num1)
					{
						k = num1 %10 ;
						num1 = num1 / 10 ;
						j++;
						if(j==1)
						{
							if(k==1)
							{
								x=x+1;
							}
						}
						if(j==2)
						{
							if(k==1)
							{
								x=x+2;
							}
						}
						if(j==3)
						{
							if(k==1)
							{
								x=x+4;
							}
						}
						if(j==4)
						{
							if(k==1)
							{
								x=x+8;
							}
						}
						if(j==5)
						{
							if(k==1)
							{
								x=x+16;
							}
						}
						if(j==6)
						{
							if(k==1)
							{
								x=x+32;
							}
						}
						if(j==7)
						{
							if(k==1)
							{
								x=x+64;
							}
						}
						if(j==8)
						{
							if(k==1)
							{
								x=x+128;
							}
						}
						if(j==9)
						{
							if(k==1)
							{
								x=x+256;
							}
						}
						if(j==10)
						{
							if(k==1)
							{
								x=x+512;
							}
						}
						if(j==11)
						{
							if(k==1)
							{
								x=x+1024;
							}
						}
					}
					HCLCD_vidSendNumber(x);
				}
			}
		}
		if(key =='n')
		{
			HCLCD_vidGoTo(0,0);
			HCLCD_vidSendString("* dec to bin ");
			HCLCD_vidGoTo(1,0);
			HCLCD_vidSendString("/ bin to dec ");
			_delay_ms(1500);
			HCLCD_vidClear();
			HCLCD_vidGoTo(0,0);
			num1=0;
			i=0;
		}
	}
}



/*int main()
{
	u8 key, key1;
	u8 i = 0;
	u32 num1 = 0;
	u32 x;
	u8 k ;
	u8 j = 0;
	keybad_inti();
	HCLCD_vidInit();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("WELCOME MOHAMED");
	_delay_ms(1500);
	HCLCD_vidClear();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("* binary to decimal");
	HCLCD_vidGoTo(1,0);
	HCLCD_vidSendString("/ decimal to binary");
	_delay_ms(1500);
	HCLCD_vidClear();

	while(1)
	{
		key=keybad_PressKey();
		if(key!=NO_KEY)
		{
			if(key>='0'&&key<='9')
			{
				i = 0;
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendNumber('key');
				num1 = num1 * 10 + ( key + '0' );
				i++;
			}
			if(key == '*')
			{
				x = 0;
				while (num1!=0)
				{
					if (num1 >= 512)
					{
						num1-=512;
						x+=1000000000;
					}
					if (num1 >= 256)
					{
						num1-=256;
						x+=100000000;
					}
					if (num1 >= 128)
					{
						num1-=128;
						x+=10000000;
					}
					if (num1 >= 64)
					{
						num1-=64;
						x+=1000000;
					}
					if (num1 >= 32)
					{
						num1-=32;
						x+=100000;
					}
					if (num1 >= 16)
					{
						num1-=16;
						x+=10000;
					}
					if (num1 >= 8)
					{
						num1-=8;
						x+=1000;
					}
					if (num1 >= 4)
					{
						num1-=4;
						x+=100;
					}
					if (num1 >= 2)
					{
						num1-=2;
						x+=10;
					}
					if (num1 >= 1)
					{
						num1-=1;
						x+=1;
					}
				}
				HCLCD_vidGoTo(1,0);
				HCLCD_vidSendNumber(x);
			}
			if(key =='n')
			{
				HCLCD_vidClear();
				HCLCD_vidGoTo(0,0);
				num1=0;
				i=0;
			}
			if (key1 == '/')
			{
				x =0;
				if(num1%10>1)
				{
					HCLCD_vidSendString("ENTER A BIN NUM");
					_delay_ms(2000);
					HCLCD_vidClear();
					num1=0;
					i=0;
				}
				else if (num1%10==1 || num1%10==0)
				{
					while(num1)
					{
						k = num1 %10 ;
						num1 = num1 / 10 ;
						j++;
						if(j==1)
						{
							if(k==1)
							{
								x=x+1;
							}
						}
						if(j==2)
						{
							if(k==1)
							{
								x=x+2;
							}
						}
						if(j==3)
						{
							if(k==1)
							{
								x=x+4;
							}
						}
						if(j==4)
						{
							if(k==1)
							{
								x=x+8;
							}
						}
						if(j==5)
						{
							if(k==1)
							{
								x=x+16;
							}
						}
						if(j==6)
						{
							if(k==1)
							{
								x=x+32;
							}
						}
						if(j==7)
						{
							if(k==1)
							{
								x=x+64;
							}
						}
						if(j==8)
						{
							if(k==1)
							{
								x=x+128;
							}
						}
						if(j==9)
						{
							if(k==1)
							{
								x=x+256;
							}
						}
						if(j==10)
						{
							if(k==1)
							{
								x=x+512;
							}
						}
						if(j==11)
						{
							if(k==1)
							{
								x=x+1024;
							}
						}
					}
					HCLCD_vidGoTo(1,0);
					HCLCD_vidSendNumber(x);
				}
			}
		}
	}
}

 */
/*int main ()
{
	DDRD =0b11110000;
	HCLCD_vidInit();
	keybad_inti();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("1.FLASH500");
	HCLCD_vidGoTo(1,0);
	HCLCD_vidSendString("2.PING PONG");
	while(1)
	{
		u8 key;
		key = keybad_PressKey();

		if(key!=NO_KEY)
		{
			if(key>='0'&& key<='9')
			{
				//HCLCD_vidClear();
				//HCLCD_vidSendData(key); //  keda ha3red lrakam
				if(key == '1' )
				{
					HCLCD_vidClear();
					HCLCD_vidGoTo(0,0);
					HCLCD_vidSendString("1.FLASHING 500ms");
					while(1)
					{
						_delay_ms(500);
						PORTD=0b11110000;
						_delay_ms(500);
						PORTD=0b00000000;
						u8 clear;
						clear = keybad_PressKey();
						if(clear == 'n')
						{
							HCLCD_vidClear();
							PORTD=0b00000000;
							HCLCD_vidGoTo(0,0);
							HCLCD_vidSendString("1.FLASHING 500ms");
							HCLCD_vidGoTo(1,0);
							HCLCD_vidSendString("2.PING PONG");
							break;
						}
					}
				}
				if(key == '2')
				{
					HCLCD_vidClear();
					HCLCD_vidSendString("2.PING PONG");
					while(1)
					{
						_delay_ms(500);
						PORTD=0b10100000;
						_delay_ms(500);
						PORTD=0b01010000;
						u8 clear;
						clear = keybad_PressKey();
						if(clear == 'n')
						{
							HCLCD_vidClear();
							PORTD=0b00000000;
							HCLCD_vidGoTo(0,0);
							HCLCD_vidSendString("1.FLASHING 500ms");
							HCLCD_vidGoTo(1,0);
							HCLCD_vidSendString("2.PING PONG");
							break;
						}
					}
				}
			}
		}
	}
}*/























