#include<stdio.h>

int main(void)
{

	printf("Enter some text\n");
	printf("This is a process with pid = %d\n", getpid());
	getchar();
	printf("current value = %d\n", getVariable());
	incrementVariable();
	printf("incremented value = %d\n",getVariable());
	getchar();
	return 0;
}
