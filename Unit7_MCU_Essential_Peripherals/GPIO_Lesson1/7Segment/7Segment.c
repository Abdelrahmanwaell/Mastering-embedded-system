/*
 * 7Segment.c
 *
 *  Created on: Apr 30, 2024
 *      Author: Dell
 */


#include "MemoryMap.h"
#include "Platform_Type.h"
#include "util/delay.h"

#define CLR_BIT(REG,PIN)			(REG &=~(1<<PIN))
#define SET_BIT(REG,PIN)			(REG |=(1<<PIN))

void GPIO_init()
{
	DDRC= 0xff ; // port C output
}

int main(void)
{	GPIO_init();
	PORTC= (PORTC&0x0F) | 0x0; //close port C initialize 7-segment with 0
	int i,j; // inner and outer loop to display number on 7-segment
	while (1)
	{
		for (i=0;i<10;i++)
		{

			for(j=0;j<10;j++)
			{   PORTC= 0b1011 | (i<<4);
				_delay_ms(30);
				PORTC= 0b0111 | (j<<4);
				_delay_ms(30);
			}
		}
	}
	return 0;
}
