/*
 ============================================================================
 Name        : EX1_find prime number between interval
 Author      : Abdelrahman wael
 Date        : 2/5/2024
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
int Is_Prime(int n)
{ int i;
	if (n==0||n==1)
		return 0;
	if	(n==2)
		return 1;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return 0;
	}
return 1;
}
void main()
{
	int num1,num2,i;
	printf("Enter two numbers (Intervals)\n");
	fflush(stdout);
	scanf("%d%d",&num1,&num2);
	printf("prime numbers between %d and %d :  ",num1,num2);
	for(i=num1;i<num2;i++)
	{

		if (Is_Prime(i))
		   printf("%d  ",i);
	}

}
