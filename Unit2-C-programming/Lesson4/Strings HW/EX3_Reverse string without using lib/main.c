/*
 *  main.c
 *  Created on: Sep 24, 2023
 *  Author: Abdelrahman Wael
 *  EX3_Reverse string without using library
 */


#include "stdio.h"
#include "string.h"

int main ()
{
	char text [100];
	char rev[100];
	int i; int j=0;

	printf ("Enter a string: ");
	fflush (stdin); fflush (stdout);
	gets(text);

	for (i=strlen(text);i>0;i--)
	{
        rev [j]=text[i-1];
        j++;
	}
	rev[strlen(text)]=0;
	printf ("Reverse String is: %s",rev);
}
