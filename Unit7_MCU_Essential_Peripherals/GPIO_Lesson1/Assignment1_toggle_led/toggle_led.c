/*
 * toggle_led.c
 *
 *  Created on: Apr 28, 2024
 *      Author: Dell
 */
#include "MemoryMap.h"
#include "Platform_Type.h"

#define CLR_BIT(REG,PIN)			(REG &=~(1<<PIN))
#define SET_BIT(REG,PIN)			(REG |=(1<<PIN))

void GPIO_init ()
{
	DDRD |= (1<<5 | 1<<6 | 1<<7 | 1<<4);

}

void my_delay(uint32 t)
{
	int i,j ;
	for(i=0;i<t;i++)
		for(j=0;i<255;i++);
}

int main (void)
{
	GPIO_init();


	while (1)
	{
		SET_BIT(PORTD,5);
		CLR_BIT(PORTD,6);
		CLR_BIT(PORTD,7);
		CLR_BIT(PORTD,4);
		my_delay(10000);

		CLR_BIT(PORTD,5);
		SET_BIT(PORTD,6);
		my_delay(10000);



		CLR_BIT(PORTD,6);
		SET_BIT(PORTD,7);
		my_delay(10000);


		CLR_BIT(PORTD,7);
		SET_BIT(PORTD,4);
		my_delay(10000);

	}
	return 0;
}
