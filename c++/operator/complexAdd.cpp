#include<iostream>
using namespace std;


//(x + i y)
class complex{ 

	public:
		complex(){}
		~complex(){}
		complex(int real, int img)
		{
		    x = real;
		    y = img;
		
		}

		void setComplex(int real, int img)
		{
			x = real;
			y = img;
		
		}
		void print(void)
		{
			cout << "x = " << x  << "    " << "y = " << y << "\n" << endl; 
		
		}
		complex operator+(complex num);
	private:
		int x;
		int y;
		
};


complex complex::operator+(complex num)
{
	
	complex temp;
	temp.x = this->x + num.x;
	temp.y = this->y + num.y;	
	return temp;


}

int main(void)
{
	complex a(10,20);
	complex b(30,40);
	complex c;
	c = a + b;
	c.print();
	return 0;
}
