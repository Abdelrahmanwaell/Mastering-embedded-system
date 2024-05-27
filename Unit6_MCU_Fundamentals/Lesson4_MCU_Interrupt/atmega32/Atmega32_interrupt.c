/*
 * Atmega32_interrupt.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Dell
 */


/*
 * Atmega32_interrupt.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Dell
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void INT0_INIT()
{
	//any logical change make interrupt
	MCUCR |= (0b01<<0);
	// : External Interrupt Request 0 Enable
	GICR |= (1<<6);
	//make PD2 input
	DDRD &=~(1<<2);

}

void INT1_INIT()
{
	//EX INT1 work with rising edge
	MCUCR |= (0b11<<2);
	// : External Interrupt Request 1 Enable
	GICR |= (1<<7);
	//make PD3 input
	DDRD &=~(1<<2);


}
void INT2_INIT()
{      // Configure PB2 (INT2) pin as input
    DDRB &= ~(1 << PB2);

    // Enable external interrupt on INT2
    GICR |= (1 << INT2);

    // Set INT2 to trigger on falling edge
    MCUCSR &= ~(1 << ISC2);

    // Enable global interrupts
    sei();


}

ISR(INT0_vect)
{
	PORTD |=(1<<5);
	_delay_ms(1000);
	PORTD &= ~(1<<5);

}

ISR(INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(1000);
	PORTD &= ~(1<<6);

}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	PORTD &= ~(1<<7);


}


int main(void)
{
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	//enable global interrupt
	SREG |= (1<<7);
	INT0_INIT();
	INT1_INIT();
	INT2_INIT();


while (1)
{

}

return 0;

}
