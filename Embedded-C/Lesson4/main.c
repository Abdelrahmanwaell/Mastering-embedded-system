/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Platform_Type.h"
#define SYSCTL_RCGC2_R     		(*((vuint32*)0x400FE108))
#define GPIO_PORTF_DATA_R 		(*((vuint32*)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((vuint32*)0x40025400))		
#define GPIO_PORTF_DEN_R        (*((vuint32*)0x4002551C))  

uint32 g_var =122;
const uint32 c_var=3;
uint32 bss_var;

int main(void) {
	vuint32 delay_count=0;
	SYSCTL_RCGC2_R=0x00000020;	//enable clock
	for(delay_count=0;delay_count<200000;delay_count++); //wait
	GPIO_PORTF_DIR_R |=1<<3;	// make portf pin3 output
	GPIO_PORTF_DEN_R |=1<<3;	//Enable Digtal input output for pin3
	while(1)

	{
		GPIO_PORTF_DATA_R |=1<<3;
		for(delay_count=0;delay_count<200000;delay_count++); //wait
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count=0;delay_count<200000;delay_count++); //wait
	}

	return 0;
}
