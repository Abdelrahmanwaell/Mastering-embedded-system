/*
 * main.c
 *  Created on: Sep 23, 2023
 * Author: Abdelrahman Wal
 * EX1_Find the frequency of characters in string
 */

#include<stdio.h>

void main()
{
	int i,freq=0;
	char text[1000],character;
	printf("\nEnter a string : ");
	fflush(stdout);
	gets(text);
    printf("\nEnter the character : ");
    fflush(stdout);fflush(stdin);
    scanf("%c",&character);
    i=0;
    while(text[i]!='\0')
    {
    	if(text[i]==character)
    	{
    		freq++;
    	}
    i++;
    }

    printf("frequency of %c= %d:",character,freq);

}
