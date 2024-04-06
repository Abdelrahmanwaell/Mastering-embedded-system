#include "uart.h"

#define UART0DR *((volatile unsigned int * const)((unsigned int *)0x101f1000))

void Uart_Send_String(unsigned char* tx_word ) 
{
	while (*tx_word!= '\0')
	{
		UART0DR= (unsigned int)(*tx_word);
		tx_word++;
	}
}
