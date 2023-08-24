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

//A template itself overloads the function 
//we can overload the template function then compiler will make use of that function 

void swapmine(char &a, char &b)
{
	
	char temp;
	temp = b;
	b    = a;
	a    = temp;
	cout << "overloaded function is called" << endl;

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
	char x = 'x';
	char y = 'y';
	swapmine(x,y);
	cout << "x = " << x << "y = " << y << endl;
	return 0;

}
