/*
 ============================================================================
 Name        : Ex3_print string in reverse using pointers.
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{   int i,j;
	char string[]="w3resource";
	char rev_string[25];
	char *ptr =string;
	int k =strlen(string);
	ptr=string+k-1;
	for (i=k,j=0;i>0;i--,j++)
	{
		rev_string[j]=*(ptr);
		ptr--;
	}
	rev_string[j]=0;
    printf("input string : %s\n",string);
    printf("output string : %s",rev_string);
}
