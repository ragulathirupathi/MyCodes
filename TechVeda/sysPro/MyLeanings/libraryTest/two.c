#include "common.h"

int sumDigits(int num)
{
	int sum = 0;
	while(num)
	{
		sum = sum + ( num % 10 );
		num = num / 10;
	}
	return sum;
}


