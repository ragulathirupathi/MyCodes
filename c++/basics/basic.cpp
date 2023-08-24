#include <iostream>
using namespace std;

class student{
  public:
  
      void setRollNo(int roll)
      {
      	rollNo = roll;  //public functions can access the data of private 
      	//members of the data and fucntions
      }
      //here all these procedure which are defined here are called 
      //inlined functions, we can still define these functions outside the 
      //class and still make them inline by using the keyword inline
      //before that object.
      void setMarks(int mar)
      {
      	marks = mar;
      }
      int getRollNo()
      {
      	return rollNo;
      }
      int  qetMarks(void)
      {
      	return (marks * 10);
      }
      
  private:
     int rollNo;
     int marks;
     int avg(void)
     {
        return qetMarks() / 50; //here it is also able to access but
        //not that usefull here. 
     }
  };

int main(void)
{
  cout << "basic" << endl;
  student A;
  A.setRollNo(10);
  cout << "RollNo" << A.getRollNo() << endl;
  A.setMarks(100); 
  return 0;
 }
