/*
 * atmega32_gpio.h
 *
 *  Created on: May 5, 2024
 *      Author: Dell
 */

#ifndef ATMEGA32_GPIO_H_
#define ATMEGA32_GPIO_H_


#include "Platform_Type.h"
#include "avr/io.h"
//-----------------------------
//Macros Configuration References
//-----------------------------
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8


//@ref GPIO_PINS_define
#define GPIO_PIN_0						((uint8)0x01) 	//pin0 selected
#define GPIO_PIN_1						((uint8)0x02)	//pin1 selected 0001
#define GPIO_PIN_2						((uint8)0x04)	//pin2 selected 0010
#define GPIO_PIN_3						((uint8)0x08)	//pin3 selected 0100
#define GPIO_PIN_4						((uint8)0x10)	//...
#define GPIO_PIN_5						((uint8)0x20)
#define GPIO_PIN_6						((uint8)0x40)
#define GPIO_PIN_7						((uint8)0x80)


//@ref GPIO_PORT_define
#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

/*@ref GPIO_PINS_State
 *
 */
#define GPIO_PIN_SET 		1
#define GPIO_PIN_RESET      0
#define GPIO_PORT_SET 		0xFF
#define GPIO_PORT_RESET      0


//@ref GPIO_MODE_define
//0: Input
//1: output
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/**================================================================
* @Fn				- MCAL_GPIO_setupPinDirection
* @brief			- Setup the direction of the required pin input/output.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_PINS_define
* @param [in] 		- direction : set Pin direction
* @retval 			- None
* Note				- If the input port number or pin number are not correct, The function will not handle the request.
*/
void MCAL_GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);


/**================================================================
* @Fn				- MCAL_GPIO_writePin
* @brief			-  Write the value SET or RESET on the required pin.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber :set Pin Number according @ref GPIO_PINS_define
* @param [in] 		- value :  set value according to @ref GPIO_PINS_State
* @retval 			- None
* Note				- If the input port number or pin number are not correct, The function will not handle the request.
* 					  If the pin is input, this function will enable/disable the internal pull-up resistor.
*/
void MCAL_GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);


/**================================================================
* @Fn				- MCAL_GPIO_readPin
* @brief			-   Read the value for the required pin
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber :set Pin Number according @ref GPIO_PINS_define
* @retval 			-  return the value for the required pin, it should be @ref GPIO_PINS_State
* Note				- If the input port number or pin number are not correct, The function will return Logic Low
*/
uint8 MCAL_GPIO_readPin(uint8 port_num, uint8 pin_num);


/**================================================================
* @Fn				- MCAL_GPIO_setupPortDirection
* @brief			- Setup the direction of the required Port input/output.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- direction : set Pin direction
* @retval 			- None
* Note				- If the input port number, The function will not handle the request.
*/
void MCAL_GPIO_setupPortDirection(uint8 port_num, uint8 direction);


/**================================================================
* @Fn				- MCAL_GPIO_writePort
* @brief			-  Write the value SET or RESET on the required Port.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- value :  set value according to @ref GPIO_PINS_State
* @retval 			- None
* Note				- If any pin in the port is output pin the value will be written.
*					  If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
* 					  If the input port number is not correct, The function will not handle the request.
*/
void MCAL_GPIO_writePort(uint8 port_num, uint8 value);


/**================================================================
* @Fn				- MCAL_GPIO_readPort
* @brief			-  Read the value for the required port
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @retval 			-  return the value for the required port, it should be @ref GPIO_PINS_State
* Note				- If the input port number or pin number are not correct, The function will return Logic Low
*/
uint8 MCAL_GPIO_readPort(uint8 port_num);
/**================================================================
* @Fn				- MCAL_GPIO_togglePin
* @brief			- toggle the value of  the required Pin.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @retval 			- None
* Note				- If the input port number is not correct, The function will not handle the request.
*/
void MCAL_GPIO_togglePin(uint8 port_num, uint8 pin_num);
/**================================================================
* @Fn				- MCAL_GPIO_togglePort
* @brief			- toggle the value of  the required Port.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber :set Pin Number according @ref GPIO_PINS_define
* @retval 			- None
* Note				- If the input port number is not correct, The function will not handle the request.
*/
void MCAL_GPIO_togglePort(uint8 port_num);



#endif /* ATMEGA32_GPIO_H_ */
