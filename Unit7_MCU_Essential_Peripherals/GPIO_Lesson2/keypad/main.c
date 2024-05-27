/*
 * main.c
 *
 *  Created on: May 7, 2024
 *      Author: Dell
 */



#include "keypad.h"
#include "atmega32_gpio.h"

int main(void)
{
	uint8 key;

	/* Use a 7-segment to display the keypad button value */
	MCAL_GPIO_setupPinDirection(PORTC_ID,GPIO_PIN_0,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(PORTC_ID,GPIO_PIN_1,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(PORTC_ID,GPIO_PIN_2,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(PORTC_ID,GPIO_PIN_3,PIN_OUTPUT);

	while(1)
	{

		/* Get the pressed button from keypad */
		key = KEYPAD_Pressed_Key();
		if((key >= 0) && (key <= 9))
		{
			MCAL_GPIO_writePort(PORTC_ID,key); /* display the key number on the 7-segment */
		}
	}
	return 0;
}

