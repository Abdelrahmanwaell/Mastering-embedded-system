/*
 * MYRTOS_FIFO.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Dell
 */

#ifndef INC_MYRTOS_FIFO_H_
#define INC_MYRTOS_FIFO_H_

/*
 * fifo.h
 *
 *  Created on: Jul 14, 2024
 *      Author: Dell
 */
#include"scheduler.h"
#include "stdint.h"
#include"stdio.h"

#ifndef FIFO_H_
#define FIFO_H_
//user config
//select element type(uint8_t , uint16-_t uint32_t ...)


#define widht1 5

element_type buff1[5];

typedef struct{

	element_type* base  ;
	element_type* head  ;
	element_type* tail  ;
	unsigned int length ;
	unsigned int count  ;
}FIFO_BUFF_t;


typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null

}FIFO_status;


//APIs





FIFO_status FIFO_enqueue(FIFO_BUFF_t* fifo, element_type item );

FIFO_status FIFO_dequeue(FIFO_BUFF_t* fifo, element_type* item );

FIFO_status FIFO_init(FIFO_BUFF_t* fifo , element_type* buff , unsigned int length );

FIFO_status FIFO_IS_full(FIFO_BUFF_t* fifo );

void FIFO_print (FIFO_BUFF_t* fifo);


#endif /* FIFO_H_ */


#endif /* INC_MYRTOS_FIFO_H_ */
