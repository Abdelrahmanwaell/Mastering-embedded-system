/*
 ============================================================================
 Name        : Ex2_print alphabets using pointer .c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char* ptr=NULL;
char alph[26];
ptr=alph;
int i;
printf("the alphabets are :\n");
for(i=0;i<26;i++)
{
	*ptr='A'+i;
	printf(" %c ",*ptr++);

}

}
