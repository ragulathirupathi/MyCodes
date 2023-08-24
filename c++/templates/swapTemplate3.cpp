#include<iostream>


using namespace std;
//template <class TypeName> function declaration 

template < class X , class Y > void printXY( X &a, Y &b)
{
	cout << "First Par = " << a << "Second Par = " << b << "\n " << endl ;
}

//We can have multiple parameters which are unknown then also templatte function is
//used seperated by commas 



//we can also use standard paramters with the template function  like below

 //template < class X > void SomeFuntion(X &a, int b)

int main(void)
{
	int a,b;
	a = 10;
	b = 20;
	printXY(a,b);
	double c = 10.5;
	double d = 20.5;
	printXY(c,d);
	char x = 'x';
	char y = 'y';
	printXY(x,y);
	return 0;

}
