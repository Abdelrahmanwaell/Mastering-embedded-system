/*
 * keypad.c
 *
 *  Created on: May 5, 2024
 *      Author: Dell
 */

#include "keypad.h"


#if (KEYPAD_NUM_COL == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
#elif (KEYPAD_NUM_COL == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
#endif


uint8 KEYPAD_Pressed_Key(void)
{ uint8 col,row;
uint8 port_value=1;


	while(1)
	{
	//
		for (col=0;col<KEYPAD_NUM_COL;col++)
		{
			MCAL_GPIO_setupPortDirection(KEYPAD_PORT,PORT_INPUT);
	//		DDRB=0x00;
			MCAL_GPIO_setupPinDirection(KEYPAD_PORT,(KEYPAD_COL_FIRST_PIN<<col),PIN_OUTPUT);
		//	DDRB|=(KEYPAD_COL_FIRST_PIN<<col);
			port_value=(~(KEYPAD_COL_FIRST_PIN<<col));
			MCAL_GPIO_writePort(KEYPAD_PORT,port_value);
			//PORTB=port_value;


			for(row=0;row<KEYPAD_NUM_ROW;row++)
				{
					if(MCAL_GPIO_readPin(KEYPAD_PORT,(KEYPAD_ROW_FIRST_PIN<<row))==GPIO_PIN_RESET)
						{
							#if (KEYPAD_NUM_COL == 3)
							return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COL)+col+1);
							#elif (KEYPAD_NUM_COL == 4)
							return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COL)+col+1);
							#endif

						}
				}
		}
	}
}






#if (KEYPAD_NUM_COL == 3)
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number)
{	uint8 keypad_buttom;
	switch (button_number)
	{
	case 10:
		keypad_buttom='*';
		break;
	case 11:
		keypad_buttom=0;
		break;
	case 12:
		keypad_buttom='#';
		break;
	default :
		keypad_buttom=button_number;
		break;

	}
	return keypad_buttom;
}

#elif (KEYPAD_NUM_COL == 4)

static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_buttom;
		switch (button_number)
		{
		case 1:
			keypad_buttom=7;
			break;
		case 2:
			keypad_buttom=8;
			break;
		case 3:
			keypad_buttom=9;
			break;
		case 4:
			keypad_buttom='%';
			break;
		case 5:
			keypad_buttom=4;
			break;
		case 6:
			keypad_buttom=5;
			break;
		case 7:
			keypad_buttom=6;
			break;
		case 8:
			keypad_buttom='*';
			break;
		case 9:
			keypad_buttom=1;
			break;
		case 10:
			keypad_buttom=2;
			break;
		case 11:
			keypad_buttom=3;
			break;
		case 12:
			keypad_buttom='-';
			break;
		case 13:
			keypad_buttom='?';
			break;
		case 14:
			keypad_buttom=0;
			break;
		case 15:
			keypad_buttom='=';
			break;
		case 16:
			keypad_buttom='+';
			break;
		default :
			keypad_buttom=button_number;
		}
	return keypad_buttom;

}
#endif
