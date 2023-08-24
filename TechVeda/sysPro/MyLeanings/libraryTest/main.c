#include <stdio.h>

//#include "common.h"


int main(void)
{
	int num;
	printf("Enter the number\r\n");
	scanf("%d",&num);
	printf("Factorial of given number is = %d\n", factorial(4,10.2,num,num,num));
	printf("Sum of digits of given number is = %d\n", sumDigits(num));
	return 0;
}
