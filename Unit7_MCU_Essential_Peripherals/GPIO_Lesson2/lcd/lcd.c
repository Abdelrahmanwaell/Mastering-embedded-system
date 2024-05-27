 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Header file for the LCD driver
 *
 * Author: Abdelrahman Wael
 *
 *******************************************************************************/

#include "lcd.h"


void LCD_init(void)
{
	MCAL_GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);
	#ifdef EIGHT_BIT_MOD
	{
		MCAL_GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);
		LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	}
	#endif

	#ifdef FOUR_BIT_MOD
	{
	MCAL_GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_D4,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_D5,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_D6,PIN_OUTPUT);
	MCAL_GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_D7,PIN_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	}
	#endif

	LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_CURSOR_BLINK);
	LCD_sendCommand(LCD_CLEAR_COMMAND);



}
void LCD_sendCommand(uint8 command)
{
	MCAL_GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,GPIO_PIN_RESET);
	MCAL_GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,GPIO_PIN_RESET);
	_delay_ms(5);

	#ifdef EIGHT_BIT_MOD
	{
		MCAL_GPIO_writePort(LCD_DATA_PORT_ID,command);
		_delay_ms(5);

	}
	#endif

	#ifdef FOUR_BIT_MOD
	{
		MCAL_GPIO_writePort(LCD_DATA_PORT_ID,        0x|(command & 0x0F));
	}
	#endif
	MCAL_GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_SET);
	_delay_ms(5);
	MCAL_GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_RESET);
	_delay_ms(5);



}
void LCD_displayCharacter(uint8 data)
{
	MCAL_GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,GPIO_PIN_SET);
	MCAL_GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,GPIO_PIN_RESET);
	_delay_ms(1);

	#ifdef EIGHT_BIT_MOD
	{
		MCAL_GPIO_writePort(LCD_DATA_PORT_ID,data);
		_delay_ms(20);


	}
	#endif

	#ifdef FOUR_BIT_MOD
	{
		MCAL_GPIO_writePort(LCD_DATA_PORT_ID,        0x|(command & 0x0F));
	}
	#endif
	MCAL_GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_RESET);
	_delay_ms(20);
}
void LCD_displayString(const char *Str)
{
	while((*Str) != '\0')
		{
			LCD_displayCharacter(*Str);
			Str++;
		}

}
void LCD_moveCursor(uint8 row,uint8 col)
{
	switch (row)
	{
		case 0:
		LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW+col);
		break;

		case 1 :
		LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW+col);
		break;

	}
}
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col);
	LCD_displayString(Str);
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
