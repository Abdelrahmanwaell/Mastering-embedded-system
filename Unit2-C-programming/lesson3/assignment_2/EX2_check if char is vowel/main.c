/*
 * main.c
 * check if char is vowel
 */


#include<stdio.h>


void main(){

	char x;
	printf("enter an alphabet:\n");
	fflush(stdout);
	scanf("%c",&x);
	if(x=='a'||x=='e'||x=='i'||x=='u'||x=='o'||x=='A'||x=='E'||x=='I'||x=='U'||x=='O')
	{
		printf("%c is vowel",x);

	}
	else
	{
		printf("%c is consonant",x);
	}


}
