/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
A()
{
    cout << "A" << endl;
}
protected:
void identity()
{
    cout << "i am base\n";
}
};

class B: public A
{
   public:
   int x;
   B()
   {
        x = 10;
       cout << "B" << endl;
   }
   void getRun() const
   {
       cout << x << endl;
   }
   using A::identity; // "using" is used to change the access specifier of the base class member function/variable in derived class.
   void identity()
   {
        A::identity();
       cout << "i am derived\n";
   }
};


int main()
{
    A a;
    B b;
    b.getRun();
    b.identity();
    return 0;
}
