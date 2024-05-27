 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Abdelrahman Wael
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include"Platform_Type.h"
#include"atmega32_gpio.h"
#include <util/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD HW Ports and Pins Ids */

#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  GPIO_PIN_1

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  GPIO_PIN_2

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   GPIO_PIN_3

#define LCD_DATA_PORT_ID               PORTA_ID

#define LCD_D4						   GPIO_PIN_4
#define LCD_D5						   GPIO_PIN_5
#define LCD_D6						   GPIO_PIN_6
#define LCD_D7						   GPIO_PIN_7



#define EIGHT_BIT_MOD
//#define FOUR_BIT_MOD
/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02

#define LCD_ENTRY_DEC   			   0x04
#define LCD_ENTRY_DEC_SHIFT   		   0x05
#define LCD_ENTRY_INC_   			   0x06
#define LCD_ENTRY_INC_SHIFT   		   0x07

#define LCD_DISP_OFF				   0x08
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_CURSOR_BLINK               0x0F

#define LCD_MOVE_DISP_RIGHT       	   0x1C
#define LCD_MOVE_DISP_LEFT   		   0x18
#define LCD_MOVE_CURSOR_RIGHT   	   0x14
#define LCD_MOVE_CURSOR_LEFT 	  	   0x10

#define LCD_BEGIN_AT_FIRST_ROW		   0x80
#define LCD_BEGIN_AT_SECOND_ROW		   0xC0

#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28



void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_clearScreen(void);

#endif /* LCD_H_ */
