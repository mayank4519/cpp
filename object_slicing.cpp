#include <iostream>
using namespace std;
class Base{
  private:
  int m_num;
  public:
     Base(int num) :
     m_num(num)
  {
  }
  int getValue(){return m_num;}
  virtual string getName(){return "base";}
};

class Derived : public Base
{
  public:
     Derived(int num):
     Base(num)
     {
     }
     string getName(){return "derived";}
};

int main()
{
    Derived derived(5);//derived has a base part and a derived part
    Base base  = derived;//copying derived object to base means Base part of derived is copied to base object.This is called as object slicing.
	// The Derived portion is not. In the example above, base receives a copy of the Base portion of derived, but not the Derived portion. That Derived portion has effectively been “sliced off”. Consequently, the assigning of a Derived class object to a Base class object is called object slicing (or slicing for short).
    cout << base.getName() << " "  << base.getValue();
    return 0;
}