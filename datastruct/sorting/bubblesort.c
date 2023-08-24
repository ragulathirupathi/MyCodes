#include"sort.h"

void BubbleSort(int *p, int length)
{
	int i,j,temp;
	for(i = 0; i < length; i++)
	{
		for(j=i+1; j < length;j++)
		{
			if(p[j] < p[i])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void PrintFunction(int *p, int length)
{
	int i = 0;
	
	printf("\n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("\n");


}
