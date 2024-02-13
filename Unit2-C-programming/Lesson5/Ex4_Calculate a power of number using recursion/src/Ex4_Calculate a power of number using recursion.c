/*
 ============================================================================
 Name        : Ex4_Calculate a power of number using recursion.c
 Author      : Abdelrahman Wael
 Version     : 2/5/2024
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
int pow(int base,int power)
{
	if (power!=0)
		return base*pow(base,power-1);
    return 1;
}

void main(void)
{
int base , power;
printf("Enter base number :\n");
fflush(stdout);
scanf("%d",&base);
printf("Enter power number  :\n");
fflush(stdout);
scanf("%d",&power);
printf("%d^%d =%d",base,power,pow(base,power));

}
