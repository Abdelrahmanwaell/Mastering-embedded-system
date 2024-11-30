/*
 * CortexMX_OS_porting.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Dell
 */

unsigned char SysTick_Led;
#include"CortexMX_OS_porting.h"


 void HardFault_Handler()
 {
	 while(1);
 }
 void MemManage_Handler()
 {
	 while(1);
 }
 void BusFault_Handler()
 {
	 while(1);
 }
 void UsageFault_Handler()
 {
	 while(1);
 }

 __attribute ((naked)) void SVC_Handler ()
 {
 	__asm("TST LR , #0x4 \n\t"
 		  "ITE EQ 		  \n\t"
 		  "MRSEQ r0 , MSP \n\t"
 		  "MRSNE r0 , PSP  \n\t"
 		  "B OS_SVC_services");
 }




void HW_init()
{
	//initialize clcok tree
	//RCC defulat value makes cpu clock & systick timer clock = 8 MHz
	//1count -> 0.125us
	//x count -> 1ms
	//x= 8000 count

	__NVIC_SetPriority(PendSV_IRQn,15);
}
void OS_Trigger_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}
void Start_Ticker()
{

	//RCC defulat value makes cpu clock & systick timer clock = 8 MHz
	//1count -> 0.125us
	//x count -> 1ms
	//x= 8000 count
	SysTick_Config(8000);
}


void SysTick_Handler()
{	MYRTOS_Update_Task_Wait_Time();
	SysTick_Led^=1;
	//Determine Pcurrent & Pnext
	decide_Whatnxt();
	//switch context and restore
	OS_Trigger_PendSV();




}
