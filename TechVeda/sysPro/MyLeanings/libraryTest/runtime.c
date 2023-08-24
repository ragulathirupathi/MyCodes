#include <stdio.h>

//#include "common.h"

#include "dlfcn.h"

int main(void)
{
	int num;
	int (*function_ptr)(int);
	printf("Enter the number\r\n");
	scanf("%d",&num);
	int  *handle;

	handle = dlopen("libtest.so",RTLD_NOW);
	if( !handle )
		return -1;

	function_ptr = dlsym(handle,"factorial");

	if(!function_ptr)
		return -2;



	printf("Factorial of given number is = %d\n", (*function_ptr)(num));
	return 0;
}
