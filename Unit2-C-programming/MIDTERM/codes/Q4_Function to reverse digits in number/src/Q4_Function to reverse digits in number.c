/*
 ============================================================================
 Name        : Q4_Function to reverse digits in number
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void reverse_digit(int num);

int main(void)
{
	reverse_digit(2457);
	reverse_digit(1057);
}
void reverse_digit(int num)
{   printf("input: %d >> output: ",num);
	int reminder;
	while(num!=0)
	{
		reminder=num%10;
		num/=10;
		printf("%d",reminder);
	}
	printf("\n");
}
