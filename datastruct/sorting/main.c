#include<stdio.h>
#include"sort.h"
int main(void)
{
	int buffer[] = {10,2,1,6,4,11,13,12,17,19,0};
	PrintFunction(buffer,(sizeof(buffer) / sizeof(int)));
	BubbleSort(buffer,(sizeof(buffer) / sizeof(int)));
	//InsertionSort(buffer,(sizeof(buffer) / sizeof(int)));
	//InsertionSort(buffer,(sizeof(buffer) / sizeof(int)));
	PrintFunction(buffer,(sizeof(buffer) / sizeof(int)));
	return 0;
}
