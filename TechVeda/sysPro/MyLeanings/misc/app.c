#include <stdio.h>

int some_data_var = 100;


const int const_var = 200;


static int some_function(void)
{

	return (++some_data_var);
	
}

int main(void)
{

	printf("All the best\r\n");

	printf("some_function_call = %d\r\n", some_function());
	
	return 0;
}
