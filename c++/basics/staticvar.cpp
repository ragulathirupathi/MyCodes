#include <iostream>
using namespace std;

class item{
 private:
 	static int count;//declaration of the static variable
 	int number;
 public:
 	void setData(int a)
 	{
 		number = a;
 		count++;
 		count2++;
 	}
 	static int count2;//declaration of the static variable
};

int item::count = 0; //definition of the static variable
int item::count2 = 0; //definition of the static variable
int main(void)
{
 
  item A; //when this is done, the static variable count is initialised to
          //zero 
  A.setData(10);
  item B,C;
  B.setData(20);
  C.setData(30);
  
 //This statement is illegal since it is static private cout << item::count << endl 
  cout << item::count2 << endl; 
  


 return 0;
}
