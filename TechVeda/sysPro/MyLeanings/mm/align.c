#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	uintptr_t address;
	int length = 0;
	if( argc < 2)
	{
		printf("Usage is incorrect\n");
		exit(0);
	}
	length = atoi(argv[1]);
	printf("given length = %d\n",length);
	char *ptr = (char*)malloc(100);	
	printf("size of pointer = %ld\n", sizeof(ptr));
	address = (uintptr_t) ptr;
	if( address % length == 0)
	{
		printf("Alligned address = %ld\n", address);
	}
	else
	{
		printf("Not alligned\n");
	}
	
	
	printf("Entering another type of allocation\n");
	{
		void *ptr;
		int size = atoi(argv[2]);
		posix_memalign(&ptr, length, size);
		address = (uintptr_t) ptr;
		if( address % length == 0)
		{
			printf("Alligned address = %ld\n", address);
		}
		else
		{
			printf("Not alligned\n");
		}
	
	}
	return 0;





}
