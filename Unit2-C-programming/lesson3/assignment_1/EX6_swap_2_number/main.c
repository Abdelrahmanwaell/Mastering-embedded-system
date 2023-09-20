/*
 * ex6.c
 *
 *  Created on: Aug 30, 2023
 *  Author: DELL
 */


#include <stdio.h>

void main(){
//setvbuf(stdout,NULL,_IONBF,0);
//setvbuf(stderr,NULL,_IONBF,0);

	int x,y,swap;

	printf("hi enter two numbers\n");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("\tbefore swaping\nfirst number: %d\nsecond number: %d\n\n",x,y);
	swap=x;
	x=y;
	y=swap;
	printf("\tafter swaping\nfirst number: %d\nsecond number: %d\n",x,y);


}
