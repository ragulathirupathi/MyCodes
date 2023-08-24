#include<iostream>


using namespace std;
//template <class TypeName> function declaration 

template < class X > void swapmine( X &a, X &b)
{
	X temp;
	temp = b;
	b    = a;
	a    = temp;
}


int main(void)
{
	int a,b;
	a = 10;
	b = 20;
	swapmine(a,b);
	cout << "a = " << a << "b = " << b << endl;
	double c = 10.5;
	double d = 20.5;
	swapmine(c,d);
	cout << "c = " << a << "d = " << b << endl;
	return 0;

}
