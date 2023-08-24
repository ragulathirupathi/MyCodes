#include <stdio.h>
#include <dlfcn.h>
int main(void)
{
	int *handle1 = NULL;
	int *handle2 = NULL;
	void (*ptr)(void);
	printf("Running main \n");
	handle1 = dlopen("./libtest2.so",RTLD_NOW);
	if( NULL == handle1 )
	{
		printf("Can not open libtest2\n");
		printf("Erroe Message is = %s\n",dlerror());
		goto error;
	}
	ptr = dlsym(handle1,"x");

	if( !ptr )
	{

		printf("Can not find the symbol\n");
		goto error;
	}

	(*ptr)();
error:
	printf("Error occurred\n");
	return 0;
}
