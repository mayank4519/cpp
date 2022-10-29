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
        cout << getName();
    }
    virtual const char* getName() {return "A";}
};

class B : public A{
    public:
     const char* getName(){return "B";} 
}; 

class C: public B{
    public:
    const char* getName(){return "C";}
};

int main()
{
    C c;
    A &a = c; // a is a reference of class A.
    cout << a.getName(); // a.getName() would resolve the class A function of derived class B.So it will always go to base funciton getName
    //but if its a virtual function, it will resolve the most derived version of that function.
    return 0;
}