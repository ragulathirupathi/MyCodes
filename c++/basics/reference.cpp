#include<iostream>
using namespace std;

int gRef = 100;
//Reference variable passing 
void swap(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

//Reference variable returning

int &ReturnReference(void)
{
 
  return gRef;
	
}
int main(void)
{
  cout << "Reference example";
  int a = 10;
  int &r = a;
  printf("r = %d\n", r);// r = 10
  r = 100;
  printf("r = %d\n",r); //r = 100
  int p = 100, q = 200;
  swap(p,q);
  printf("After swapping p = %d, q = %d\n", p,q);
  ReturnReference() = 200;  
  printf("Return Reference = %d\n", gRef);
  return 0;
}
