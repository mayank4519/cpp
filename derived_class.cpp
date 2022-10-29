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
};


int main()
{
    A a;
    B b;
    b.getRun();
    return 0;
}
