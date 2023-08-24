//Friend function explanation ,
//A friend function is the function when declared in class, it can access the
//private variables of the class. In general a friend function takes the 
//objects as the function parameters.

//A friend function can be declared in the public or private 
//section of the class which does not effect any functionality
//syntax of the friend fucntion declaration is 
// friend returnType functionname(class Type obj);


//A friend function can be declared in private or public section of the class
//and the defintion of the function can be enywhere

//A friend function does not belong to any class, since it does not belong
//to any class we can not use any object to invoke the functon. It should be
//called like any other normal functions. 

//Unlike other normal memeber funtions a friend function can not `directly 
//access the private variables, it should have the object to use the . operations

//usually objects are the arguments to the friend function
#include<iostream>
using namespace std;

//class A;//Forward declaration of the class



class A
{
	public:
		void setMN(int x, int y)
		{
			m = n;
			n = y;
		}
		friend int SumMN(A obj);
	private:
		int m;
		int n;
		//friend int SumMN(A obj); same as above did not show
		//any impact

};

int SumMN( A obj)
{
    //We are able to access the m & n with "." operator even 
    //they are private members of the class as "SumMN" is 
    //declared as a friend fucntion in class A
    return ( obj.m + obj.n ); 

}
int main(void)
{
	class A obj1;
	obj1.setMN(10,30);
	cout << " The sum is =" << SumMN(obj1) << endl;
	//obj1.SumMN(obj1);  This is illegal type of friend fucntion calling
	return 0;
} 
