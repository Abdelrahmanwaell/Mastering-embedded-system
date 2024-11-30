/*
 * CortexMX_OS_porting.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Dell
 */

#ifndef INC_CORTEXMX_OS_PORTING_H_
#define INC_CORTEXMX_OS_PORTING_H_

#include"core_cm3.h"

#define MAIN_STACK_SIZE   3072
extern unsigned int _estack;
extern unsigned int _eheap;

#define OS_SET_PSP(add)						__asm volatile (" mov r0 , %0 \n\t msr PSP , r0 " : : "r" (add))
#define OS_GET_PSP(add)						__asm volatile (" mrs r0 , PSP \n\t mov %0 , r0 " : "=r"   (add))

#define OS_SWITCH_SP_to_PSP					__asm volatile (" MRS r0, CONTROL \n\t mov r1 , #0x2 \n\t ORR r0 , r0 ,r1 \n\t MSR CONTROL ,r0 ")
#define OS_SWITCH_SP_to_MSP					__asm volatile (" MRS r0, CONTROL \n\t mov r1 , #0x5 \n\t AND r0 , r0 ,r1 \n\t MSR CONTROL ,r0 ")

#define SWITCH_CPU_PRIVILEGED					__asm("MRS r3, CONTROL \n\t" "LSR r3,r3,#0x1 \n\t" "LSL r3,r3,#0x1 \n\t" "MSR CONTROL,r3 ");
#define SWITCH_CPU_NONPRIVILEGED				__asm("MRS r3, CONTROL \n\t" "ORR r3,r3,#0x1 \n\t" "MSR CONTROL,r3 ");


void OS_Trigger_PendSV();
void Start_Ticker();
#endif /* INC_CORTEXMX_OS_PORTING_H_ */
