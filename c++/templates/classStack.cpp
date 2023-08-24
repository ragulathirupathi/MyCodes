#include<iostream>


using namespace std;


#define MAX_STACK 10

template < class X > class stack{
	
	public:	
	stack()
	{
	
		top = -1;
	}	
	void printData(void);
	void push(X);
	X pop();		
	private:
	
	int top;
	X array[MAX_STACK];
	
};


template< class X > void stack<X>::printData(void)
{
	while(top != -1)
	{
	  cout << array[top] << "\n" << endl;
	  top--;
	}	


}


template< class X > void stack<X>::push(X a)
{
	if( top <  MAX_STACK - 1)
	{
		top++;
		array[top] = a;
	
	}
	else
	{
	  cout << "stack full"  << "\n" << endl;	
	
	}	


}


template< class X > X stack<X>::pop(void)
{
	X temp;
	if( top ==  -1)
	{
		temp = array[top];
		top--;
	
	}
	else
	{
	  cout << "stack empty"  << "\n" << endl;	
	
	}
	return temp;	

}


int main(void)
{
	stack<int>pintStack;
	pintStack.push(10);
	pintStack.push(20);
	pintStack.push(30);
	pintStack.push(40);		
	pintStack.push(50);
	pintStack.push(60);
	pintStack.push(70);
	pintStack.push(80);
	pintStack.printData();
	stack<char>charStack;
	charStack.push('a');
	charStack.push(20);
	charStack.push(30);
	charStack.push(40);		
	charStack.push(50);
	charStack.push(60);
	charStack.push(70);
	charStack.push(80);
	charStack.printData();
	return 0;
}



