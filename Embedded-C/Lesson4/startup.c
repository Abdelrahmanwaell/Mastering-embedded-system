#include "Platform_Type.h"

extern int main(void);
extern uint32 _E_TEXT;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

static uint32 stack_top[256];

void Reset_Handler();
void Default_Handler();

void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void H_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Bus_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));



void (*(g_p_fn_vectors[]))() __attribute__((section(".vectors"))) = {

	(void (*)()) ((uint32)stack_top+sizeof(stack_top)),
	&Reset_Handler,		/* -3 Reset */
	&NMI_Handler,			/* -2 NMI */
	&H_Fault_Handler,		/* -1 Hard Fault */
	&MM_Fault_Handler,		/* 0 MM Fault */
	&Bus_Fault_Handler,	/* 1 Bus Fault */
	&Usage_Fault_Handler	/* 2 Usage Fault */
};




void Reset_Handler()
{
	/* Copy .data from flash to sram */
	int i=0;
	uint32 DATA_size = (uint8*)(&_E_DATA) - (uint8*)(&_S_DATA);
	uint8* P_SRC = (uint8*)(&_E_TEXT);
	uint8* P_DST = (uint8*)(&_S_DATA);
	for(i=0; i<DATA_size; i++){
		*((uint8*)P_DST++) = *((uint8*)P_SRC++);
	}
	
	/* init .BSS in sram = 0 */
	uint32 bss_size = (uint8*)(&_E_BSS) - (uint8*)(&_S_BSS);
	P_DST = (uint8*)(&_S_BSS);
	for(i=0; i<bss_size; i++){
		*((uint8*)P_DST++) = (uint8)0;
	}
	
	/* Jump to main() */
	main();
}

void Default_Handler()
{
	Reset_Handler();
}