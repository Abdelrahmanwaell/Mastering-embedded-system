/*
 * Platform_Type.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Dell
 */

#ifndef PLATFORM_TYPE_H_
#define PLATFORM_TYPE_H_
#include <stdbool.h>



/*****************boolean***************/
#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE   (boolean)false
#endif

#ifndef TRUE
#define TRUE   (boolean)true
#endif

typedef _Bool  boolean;
/*****************unsigned***************/
typedef unsigned char                  uint8;
typedef volatile unsigned char         vuint8;
typedef unsigned short                 uint16;
typedef volatile unsigned short        vuint16;
typedef unsigned int                   uint32;
typedef volatile unsigned int          vuint32;
typedef unsigned long long             uint64;
typedef volatile unsigned long long    vuint64;


/*****************signed***************/
typedef signed char                  sint8;
typedef volatile signed char         vsint8;
typedef signed short                 sint16;
typedef volatile signed short        vsint16;
typedef signed int                   sint32;
typedef volatile signed int          vsint32;
typedef signed long long             sint64;
typedef volatile signed long long    vsint64;

#endif /* PLATFORM_TYPE_H_ */
