#include "sort.h"

void swap(int *a, int *b)
{
	int temp;
	//second element is less than first then only swap
	if(*b < *a)
	{
		temp = *b;
		*b = *a;
		*a =  temp;
	}

}

void InsertionSort(int *p, int n)
{
	int i,j,key;
	for(i = 0; i < n; i++)
	{
		key = p[i];
		j = i-1;
		while((j >= 0) && (p[j] > key) )
		{
			p[j+1] = p[j];
			j--;
		}
		p[j+1] = key;
	}
}
