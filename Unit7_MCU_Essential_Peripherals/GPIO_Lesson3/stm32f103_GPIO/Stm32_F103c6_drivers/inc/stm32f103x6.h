/*
 * stm32f103x6.h
 *
 *  Created on: May 1, 2024
 *      Author: Dell
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_



//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include "Platform_Type.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Memory_BASE							0x08000000UL
#define System_Memory_BASE							0x1FFFF000UL
#define SRAM_BASE									0x20000000UL

#define Peripherals_BASE							0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE 		0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE 									0x40021000UL
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//PORTA and PORTB fully included in LQFP48 package
#define GPIOA_BASE									0x40010400UL
#define GPIOB_BASE									0x40010C00UL
//PORTC and PORTD partially included in LQFP48 package
#define GPIOC_BASE									0x40011000UL
#define GPIOD_BASE									0x40011400UL
//PORTE not included  in LQFP48 package
#define GPIOE_BASE									0x40011800UL

//AFIO
#define AFIO_BASE									0x0x40010000UL
//EXI
#define EXTI_BASE									0x40010400UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	vuint32 CR;
	vuint32 CFGR;
	vuint32 CIR;
	vuint32 APB2RSTR;
	vuint32 APB1RSTR;
	vuint32 AHBENR;
	vuint32 APB2ENR;
	vuint32 APB1ENR;
	vuint32 BDCR;
	vuint32 CSR;
	vuint32 AHBSTR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	vuint32 CRL;
	vuint32 CRH;
	vuint32 IDR;
	vuint32 ODR;
	vuint32 BSRR;
	vuint32 BRR;
	vuint32 LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	vuint32 EVCR;
	vuint32 MAPR;
	vuint32 EXTICR1;
	vuint32 EXTICR2;
	vuint32 EXTICR3;
	vuint32 EXTICR4;
	vuint32 RESERVED;
	vuint32 MAPR2;
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	vuint32 IMR;
	vuint32 EMR;
	vuint32 RTSR;
	vuint32 FTSR;
	vuint32 SWIER;
	vuint32 PR;
}EXTI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 						((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB 						((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC 						((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD 						((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE 						((GPIO_TypeDef*)GPIOE_BASE)
#define EXTI 						((EXTI_TypeDef*)EXTI_BASE)
#define AFIO 						((AFIO_TypeDef*)AFIO_BASE)
#define RCC 						((RCC_TypeDef*)RCC_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()					(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()					(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()					(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()					(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()					(RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()					(RCC->APB2ENR |= 1<<0)



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X6_H_ */
