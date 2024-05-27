/*
 * Stm32_F103c6_gpio_driver.c
 *
 *  Created on: May 1, 2024
 *  Author: Abdelrahman Wael
 *
 */
#include "Stm32_F103c6_gpio_driver.h"

/**================================================================
* @Fn				- get_CRLH_postion
* @brief			- fn to initialize PORTx PINy according to Parameter specified in PinConfig
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinConfig : The configuration information for the specified GPIO Pin
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
static uint8 get_CRLH_postion(uint16 PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1 :
		return 4;
		break;

	case GPIO_PIN_2 :
		return 8;
		break;

	case GPIO_PIN_3 :
		return 12;
		break;

	case GPIO_PIN_4 :
		return 16;
		break;

	case GPIO_PIN_5 :
		return 20;
		break;

	case GPIO_PIN_6 :
		return 24;
		break;

	case GPIO_PIN_7 :
		return 28;
		break;

	case GPIO_PIN_8 :
		return 0;
		break;

	case GPIO_PIN_9 :
		return 4;
		break;

	case GPIO_PIN_10 :
		return 8;
		break;

	case GPIO_PIN_11 :
		return 12;
		break;

	case GPIO_PIN_12 :
		return 16;
		break;

	case GPIO_PIN_13 :
		return 20;
		break;

	case GPIO_PIN_14 :
		return 24;
		break;

	case GPIO_PIN_15 :
		return 28;
		break;
	default:
		break;
	}
 return 0;
}
/**================================================================
* @Fn				- MCAL_GPIO_Init
* @brief			- fn to initialize PORTx PINy according to Parameter specified in PinConfig
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinConfig : The configuration information for the specified GPIO Pin
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx,GPIO_PinConfi_t *PinConfig)
{
	volatile uint32* configregister =NULL;
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH;

	//clear CNF and MODE bits [4bits]
	(*configregister)&=~(0xF<<get_CRLH_postion(PinConfig->GPIO_PinNumber));
	uint8 configration=0;


	//if output
	if ((PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_OD)||(PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_PP)||(PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_OD)||(PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_PP))
	{
		// Set CNF8[1:0] MODE8[1:0]
		configration=((((PinConfig->GPIO_MODE-4)<<2)|(PinConfig->GPIO_Output_Speed))&0x0F);

	}
	//if INPUT
	//MODE[1:0]00: Input mode (reset state)
	else
	{
		if ((PinConfig->GPIO_MODE== GPIO_MODE_INPUT_FLO)||(PinConfig->GPIO_MODE==GPIO_MODE_ANALOG))
		{
			configration=(((PinConfig->GPIO_MODE)<<2)&0x0C);
		}
		else if(PinConfig->GPIO_MODE== GPIO_MODE_INPUT_AF_OD)// Considered that GPIO_MODE_AF_INPUT = GPIO_MODE_INPUT_FLO in data sheet
		{
			configration=(((GPIO_MODE_INPUT_FLO)<<2)&0x0C);
		}
		else //INPUT PD OR INPUT PU
		{
			configration=(((GPIO_MODE_INPUT_PU)<<2)&0x0C);
			if ((PinConfig->GPIO_MODE== GPIO_MODE_INPUT_PD))
				{
				// PxODR = 0 Input pull-down: Table 20. Port bit configuration table
				GPIOx->ODR &=~(PinConfig->GPIO_PinNumber);
				}
			else
			   {
				// PxODR = 1 Input pull-up: Table 20. Port bit configuration table
				GPIOx->ODR |=(PinConfig->GPIO_PinNumber);

			   }
		}

	}
	//write on CRL/CRH
	(*configregister) |= (configration << get_CRLH_postion(PinConfig->GPIO_PinNumber));
}
/**================================================================
* @Fn				- MCAL_GPIO_DeInit
* @brief			- fn to reset PORTx
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
void 	MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx)
{
	//	GPIOx->CRL = 0x44444444;
	//	GPIOx->CRH = 0x44444444;
	//	//GPIOx->IDR (Read only)
	//	GPIOx->ODR = 0x00000000;
	//	GPIOx->BSRR = 0x00000000;
	//	GPIOx->BRR = 0x00000000;
	//	GPIOx->LCKR = 0x00000000;

	//  reset controller
	if (GPIOx==GPIOA)
	{
		RCC->APB2RSTR |=1<<2;
		RCC->APB2RSTR &=~(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR |=1<<3;
		RCC->APB2RSTR &=~(1<<3);
	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR |=1<<4;
		RCC->APB2RSTR &=~(1<<4);
	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR |=1<<5;
		RCC->APB2RSTR &=~(1<<5);
	}
	else if(GPIOx==GPIOE)
	{
		RCC->APB2RSTR |=1<<6;
		RCC->APB2RSTR &=~(1<<6);

	}

}
/**================================================================
* @Fn				- MCAL_GPIO_ReadPin
* @brief			- fn to read specified  PINy
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_PINS_define
* @retval 			- the input Pin value (two value based on @ref GPIO_PIN_state)
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
uint8 	MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16 PinNumber)
{
		uint8 bit_status;
		if( ((GPIOx->IDR) & PinNumber)!=GPIO_PIN_RESET)
		{
			bit_status =GPIO_PIN_SET;
		}
		else
		{
			bit_status =GPIO_PIN_RESET;

		}
	return bit_status;
}
/**================================================================
* @Fn				- MCAL_GPIO_ReadPort
* @brief			- fn to read specified  Port
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @retval 			- the input Port value value
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
uint16 	MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	return (uint16)GPIOx->IDR ;
}
/**================================================================
* @Fn				- MCAL_GPIO_WritePin
* @brief			- fn to write specified  PINy
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_PINS_define
* @param [in] 		- value : write Pin value (two value based on @ref GPIO_PIN_state)
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
void  MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16 PinNumber,uint8 value)
{
	if (value!=GPIO_PIN_RESET)//set_bit
	{
//		GPIOx->ODR|=PinNumber;
//		Port bit set/reset register
		GPIOx->BSRR=(uint32)PinNumber;
	}
	else//reset
		{
//		Port bit reset register
		GPIOx->BRR=(uint32)PinNumber;
		}

}

/**================================================================
* @Fn				- MCAL_GPIO_WritePort
* @brief			- fn to write specified  PORTx
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- value :  write Port value
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
void  MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16 value)
{
	GPIOx->ODR=(uint32)value;
}
/**================================================================
* @Fn				- MCAL_GPIO_TogglePin
* @brief			- fn to toggle specified  Piny
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_PINS_define
* @retval 			- None
* Note				- STM32F103C6 has GPIO A,B,C,D,E module but LQFP48 package has only GPIO A,B,part of C/D exported as external PINS from the MCU
*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16 PinNumber)
{
	GPIOx->ODR^=((uint32)PinNumber);
}
/**================================================================
* @Fn				- MCAL_GPIO_LockPin
* @brief			- the locking mechansim allow IO configuration to be frozen
* @param [in] 		- GPIOx : where x can be (A...E according to device selected) to select GPIO peripheral
* @param [in] 		- PinNumber : set Pin Number according @ref GPIO_RETURN_LOCK
* @retval 			- OK if pin config is locked or ERORR if pin is not locked
* Note
*/
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx,uint16 PinNumber)
{
//	CKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	vuint32 temp=1<<16;
	temp |=PinNumber;
//	LOCK key writing sequence:
//	Write 1
	GPIOx->LCKR=temp;

//	Write 0
	GPIOx->LCKR=PinNumber;

//	Write 1
	GPIOx->LCKR=temp;

//	Read 0
	temp=GPIOx->LCKR;
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock

	if (GPIOx->LCKR &(1<<16) )

	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_Eror;
	}



}
