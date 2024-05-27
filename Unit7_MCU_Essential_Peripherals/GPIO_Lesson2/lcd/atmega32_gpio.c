/*
 * atmega32_gpio.c
 *
 *  Created on: May 5, 2024
 *      Author: Dell
 */
#include "atmega32_gpio.h"

/**================================================================
* @Fn				- MCAL_GPIO_setupPinDirection
* @brief			- Setup the direction of the required pin input/output.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_PINS_define
* @param [in] 		- direction : set Pin direction
* @retval 			- None
* Note				- If the input port number or pin number are not correct, The function will not handle the request.
*/
void MCAL_GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{

		switch (port_num)
		{
		case PORTA_ID :
			if(direction==PIN_OUTPUT)
			{
				//SET_BIT
				DDRA|=pin_num;
			}
			else
			{ 	//CLEAR_BIT
				DDRA&=(~pin_num);
			}
		break;

		case PORTB_ID :
			if(direction==PIN_OUTPUT)
			{
				//SET_BIT
				DDRB|=pin_num;
			}
			else
			{ 	//CLEAR_BIT
				DDRB&=(~pin_num);
			}
		break;

		case PORTC_ID :
			if(direction==PIN_OUTPUT)
			{
				//SET_BIT
				DDRC|=pin_num;
			}
			else
			{ 	//CLEAR_BIT
				DDRC&=(~pin_num);
			}
		break;

		case PORTD_ID :
			if(direction==PIN_OUTPUT)
			{
				//SET_BIT
				DDRD|=pin_num;
			}
			else
			{ 	//CLEAR_BIT
				DDRD&=(~pin_num);
			}
		break;

		}


}


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
void MCAL_GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{

			switch (port_num)
			{
			case PORTA_ID :
				if(value==GPIO_PIN_SET)
				{
					//SET_BIT
					PORTA|=pin_num;
				}
				else
				{ 	//CLEAR_BIT
					PORTA&=~pin_num;
				}
			break;

			case PORTB_ID :
				if(value==GPIO_PIN_SET)
				{
					//SET_BIT
					PORTB|=pin_num;
				}
				else
				{ 	//CLEAR_BIT
					PORTB&=~pin_num;
				}
			break;

			case PORTC_ID :
				if(value==GPIO_PIN_SET)
				{
					//SET_BIT
					PORTC|=pin_num;
				}
				else
				{ 	//CLEAR_BIT
					PORTC&=~pin_num;
				}
			break;

			case PORTD_ID :
				if(value==GPIO_PIN_SET)
				{
					//SET_BIT
					PORTD|=pin_num;
				}
				else
				{ 	//CLEAR_BIT
					PORTD&=~pin_num;
				}
			break;

			}

	}


/**================================================================
* @Fn				- MCAL_GPIO_readPin
* @brief			-   Read the value for the required pin
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber :set Pin Number according @ref GPIO_PINS_define
* @retval 			-  return the value for the required pin, it should be @ref GPIO_PINS_State
* Note				- If the input port number or pin number are not correct, The function will return Logic Low
*/
uint8 MCAL_GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 PinValue=0;

			switch (port_num)
			{
			case PORTA_ID :
				if(PINA&pin_num)
				{

					PinValue=GPIO_PIN_SET;
				}
				else
				{
					PinValue=GPIO_PIN_RESET;
				}
			break;

			case PORTB_ID :
				if(PINB&pin_num)
				{

					PinValue=GPIO_PIN_SET;
				}
				else
				{
					PinValue=GPIO_PIN_RESET;
				}
			break;

			case PORTC_ID :
				if(PINC&pin_num)
				{

					PinValue=GPIO_PIN_SET;
				}
				else
				{
					PinValue=GPIO_PIN_RESET;
				}
			break;

			case PORTD_ID :
				if(PIND&pin_num)
				{

					PinValue=GPIO_PIN_SET;
				}
				else
				{
					PinValue=GPIO_PIN_RESET;
				}
			break;

			}

	return PinValue;

}


/**================================================================
* @Fn				- MCAL_GPIO_setupPortDirection
* @brief			- Setup the direction of the required Port input/output.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- direction : set Pin direction
* @retval 			- None
* Note				- If the input port number, The function will not handle the request.
*/
void MCAL_GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{


		switch (port_num)
		{
		case PORTA_ID :

				DDRA=direction;

		break;

		case PORTB_ID :

				DDRB=direction;

		break;

		case PORTC_ID :


				DDRC=direction;

		break;

		case PORTD_ID :

				DDRD=direction;

		break;

		}

}


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
void MCAL_GPIO_writePort(uint8 port_num, uint8 value)
{

				switch (port_num)
				{
				case PORTA_ID :
					PORTA=value;
				break;

				case PORTB_ID :
					PORTB=value;
				break;

				case PORTC_ID :
					PORTC=value;
				break;

				case PORTD_ID :
					PORTD=value;
				break;

				}
}


/**================================================================
* @Fn				- MCAL_GPIO_readPort
* @brief			-  Read the value for the required port
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @retval 			-  return the value for the required port, it should be @ref GPIO_PINS_State
* Note				- If the input port number or pin number are not correct, The function will return Logic Low
*/
uint8 MCAL_GPIO_readPort(uint8 port_num)
{
	uint8 PortValue=0;

				switch (port_num)
				{
				case PORTA_ID :
					PortValue=PINA;

				break;

				case PORTB_ID :
					PortValue=PINB;
				break;

				case PORTC_ID :
					PortValue=PINC;
				break;

				case PORTD_ID :
					PortValue=PIND;
				break;

				}

		return PortValue;
}
/**================================================================
* @Fn				- MCAL_GPIO_togglePin
* @brief			- toggle the value of  the required Pin.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @retval 			- None
* Note				- If the input port number is not correct, The function will not handle the request.
*/
void MCAL_GPIO_togglePin(uint8 port_num, uint8 pin_num)
{


					switch (port_num)
					{
					case PORTA_ID :
						PORTA^=pin_num;
					break;

					case PORTB_ID :
						PORTB^=pin_num;
					break;

					case PORTC_ID :
						PORTC^=pin_num;
					break;

					case PORTD_ID :
						PORTD^=pin_num;
					break;

					}


}

/**================================================================
* @Fn				- MCAL_GPIO_togglePort
* @brief			- toggle the value of  the required Port.
* @param [in] 		- port_num : set port number @ref GPIO_PORT_define
* @param [in] 		- PinNumber :set Pin Number according @ref GPIO_PINS_define
* @retval 			- None
* Note				- If the input port number is not correct, The function will not handle the request.
*/
void MCAL_GPIO_togglePort(uint8 port_num)
{


					switch (port_num)
					{
					case PORTA_ID :
						PORTA^=0xFF;
					break;

					case PORTB_ID :
						PORTB^=0xFF;
					break;

					case PORTC_ID :
						PORTC^=0xFF;
					break;

					case PORTD_ID :
						PORTD^=0xFF;
					break;

					}


}

