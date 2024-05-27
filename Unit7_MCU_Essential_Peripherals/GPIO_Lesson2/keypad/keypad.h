/*
 * keypad.h
 *
 *  Created on: May 5, 2024
 *      Author: Dell
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "atmega32_gpio.h"

#define KEYPAD_NUM_COL				4
#define KEYPAD_NUM_ROW				4

#define KEYPAD_PORT					PORTB_ID

#define KEYPAD_ROW_FIRST_PIN		GPIO_PIN_0
#define KEYPAD_COL_FIRST_PIN		GPIO_PIN_4

#define KEYPAD_PRESSED				GPIO_PIN_RESET






uint8 KEYPAD_Pressed_Key(void);



#endif /* KEYPAD_H_ */
