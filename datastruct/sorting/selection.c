#include "sort.h"

void selection(int *p, int length)
{
	int i, j,minIndex, temp ;
	for(i = 0; i < length; i++)
	{
		minIndex = i;
		for(j = i+1; j < length; j++)
		{
			if(p[j] < p[i])
			{
				minIndex = j;
			}
		}
		if(minIndex != i)
		{
			temp = p[minIndex];
			p[minIndex] = p[i];
			p[i] = temp;
		}
	}


}
