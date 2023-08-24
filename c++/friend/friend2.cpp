#include<iostream>


using namespace std;

class coordinates
{
   private:
   	int x;
   	int y;
   protected:
   	int z;
   public:
   	int setC(int a, int b, int c);
   	int modifyC(coordinates &refObj);
   	void showC(void)
   	{
   		cout << "x = " << x << endl;
   		cout << "y = " << y << endl;
   		cout << "z = " << z << endl;
   	
   	}
   	friend int modifyC(coordinates &refObj);
};


inline int coordinates::setC(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
	return 0;

}

int modifyC(coordinates &refObj)
{
	refObj.x = refObj.x + 10;
	refObj.y = refObj.y + 10;
	refObj.z = refObj.z + 10;
	return 0;
}


int main(void)
{
	coordinates obj;
	obj.setC(10,20,30);  		
	obj.showC();
	modifyC(obj);
	obj.showC();
	return 0;
}
