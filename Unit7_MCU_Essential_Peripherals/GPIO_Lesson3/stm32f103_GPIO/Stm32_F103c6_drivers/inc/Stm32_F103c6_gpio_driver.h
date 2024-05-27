/*
 * Stm32_F103c6_gpio_driver.h
 *
 *  Created on: May 1, 2024
 *      Author: Dell
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint8 GPIO_PinNumber ; 		// specifies the GPIO pins to be configured
						  	  	//  This parameter can be a value of @ref GPIO_PINS_define

	uint8 GPIO_MODE;     		//   specifies the operating mode for the selected pins
								//    This parameter can be a value of @ref GPIO_MODE_define

	uint8 GPIO_Output_Speed;	//   specifies the speed for the selected pins
								//    This parameter can be a value of @ref GPIO_SPEED_define



}GPIO_PinConfi_t;
//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINS_define
#define GPIO_PIN_0						((uint16)0x0000) 	//pin0 selected
#define GPIO_PIN_1						((uint16)0x0002)	//pin1 selected 0001
#define GPIO_PIN_2						((uint16)0x0004)	//pin2 selected 0010
#define GPIO_PIN_3						((uint16)0x0008)	//pin3 selected 0100
#define GPIO_PIN_4						((uint16)0x0010)	//...
#define GPIO_PIN_5						((uint16)0x0020)
#define GPIO_PIN_6						((uint16)0x0040)
#define GPIO_PIN_7						((uint16)0x0080)
#define GPIO_PIN_8						((uint16)0x0100)
#define GPIO_PIN_9						((uint16)0x0200)
#define GPIO_PIN_10						((uint16)0x0400)
#define GPIO_PIN_11						((uint16)0x0800)
#define GPIO_PIN_12						((uint16)0x1000)
#define GPIO_PIN_13						((uint16)0x2000)
#define GPIO_PIN_14						((uint16)0x4000)
#define GPIO_PIN_15						((uint16)0x8000)

#define GPIO_PIN_all					((uint16)0xFFFF)
#define GPIO_PIN_MASK 					0x0000FFFFu  			//pin mask fo assert test

//@ref GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function Input

#define GPIO_MODE_ANALOG				0x00000000u		//analog mode
#define GPIO_MODE_INPUT_FLO				0x00000001u		//Floating input
#define GPIO_MODE_INPUT_PU				0x00000002u		//Input with Pull-up
#define GPIO_MODE_INPUT_PD				0x00000003u		//Input with Pull-down
#define GPIO_MODE_OUTPUT_PP				0x00000004u		//Output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u		//Output open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u		//Alternate function push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u		//Alternate function open-drain
#define GPIO_MODE_INPUT_AF_OD			0x00000008u		//Alternate function Input


/*@ref GPIO_SPEED_define
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
 */
#define GPIO_SPEED_10M    			0x00000001u //output mode with max speed 10 MHz
#define GPIO_SPEED_2M    			0x00000002u //Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M    			0x00000003u //Output mode, max speed 50 MHz.

/*@ref GPIO_PINS_State
 *
 */
#define GPIO_PIN_SET 		1
#define GPIO_PIN_RESET      0

/*@ref GPIO_RETURN_LOCK
 *
 */
#define GPIO_RETURN_LOCK_Enabled		1
#define GPIO_RETURN_LOCK_Eror		    0

/*@ref Module_REF_NAME_define

* ==================================================================================================================================================================
* 														APIs Supported by "MCAL GPIO DRIVER"
* =================================================================================================================================================================
*
*/
void 	MCAL_GPIO_Init (GPIO_TypeDef *GPIOx,GPIO_PinConfi_t *PinConfig);
void 	MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx);

uint8 	MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16 PinNumber);
uint16 	MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void  MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16 PinNumber,uint8 value);
void  MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16 value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16 PinNumber);
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx,uint16 PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
