/*
 * MemoryMap.h
 *
 *  Created on: Apr 28, 2024
 *      Author: Dell
 */

#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define PORTA  (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*) 0x35)
#define PORTD (*(volatile unsigned char*)0x32)

#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#endif /* MEMORYMAP_H_ */
