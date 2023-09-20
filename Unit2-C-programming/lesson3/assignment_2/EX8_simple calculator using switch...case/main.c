/*
 * main.c
 *
 * simple calculator using switch...case
 */


#include <stdio.h>

void main()
{
	char operator;
	float x,y;
	simple_calc :
	printf(" Enter operator either + or - or / or * : ");
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operands : ");
	fflush(stdout);
	scanf("%f%f",&x,&y);

	switch(operator)
	{

	case '+' :
		printf ("%.1f %c %.1f = %.1f",x,'+',y,x+y);

		break;

	case '-' :
		printf ("%.1f %c %.1f = %.1f",x,'-',y,x-y);

		break;

	case'*' :
		printf ("%.1f %c %.1f = %.1f",x,'*',y,x*y);

		break;

	case'/' :
		printf ("%.1f %c %.1f = %.1f",x,'/',y,x/y);

		break;

	default :
		printf("error\n");
		goto simple_calc;
		break;


	}















}
