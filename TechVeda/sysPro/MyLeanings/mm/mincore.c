#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
int main(void)
{

crash:
	int pageSize= 0;
	pageSize = getpagesize();
	void *ptr;
	int size = pageSize * 5;
	posix_memalign(&ptr,pageSize,size); //allocate 5 pages of the data which is page aligned
	
	
	unsigned char minvector[5];
	
	memset(ptr,0,size);
	
	mincore(ptr, size, minvector);
	
	
	
	for(int index = 0; index < 5; index++)
	{
		if(minvector[index] & 1)
		{
			printf("physical memory present at index = %d\n",index);
		}
		else
		{
			
			printf("Not present\n");
		}
	}
	goto crash;
	return 0;
}
	
	
