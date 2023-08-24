#include<stdio.h>
typedef void* (*TestPointer)(void*);


typedef struct node NODE;

struct node{
	int a;
	NODE *ptr;

};
	
	
#pragma pack(1)	 //one way
struct padding{
	int a;
	char b;
	int c;
	double a;


};



//another way


struct pad2{
	int a;
	char b;
	int c;
	double d;
	


}__attribute__((packed));


int main(void)
{



	return 0;
}
