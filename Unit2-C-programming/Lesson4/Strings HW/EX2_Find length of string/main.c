/*
 * main.c
 *  Created on: Sep 24, 2023
 *  Author: Abdelrahman Wael
 *  EX2_find length of string
 */

#include<stdio.h>

void main()
{
	int i=0;
	char text[100];
	printf("Enter the string: \n");
	fflush(stdout);fflush(stdin);
	gets(text);

	while(text[i]!=0)
	{
		i++;

	}

	printf( "length of string : %d",i);
}
