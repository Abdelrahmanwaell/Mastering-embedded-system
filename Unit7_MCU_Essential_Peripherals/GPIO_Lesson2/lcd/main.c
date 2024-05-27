/*
 * main.c
 *
 *  Created on: May 21, 2024
 *      Author: Dell
 */
#include "stdio.h"
#include "lcd.h"
int main(void)
{
LCD_init();
//
LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW);

LCD_displayStringRowColumn(0,2,"hi")	;




	return 0;
}
