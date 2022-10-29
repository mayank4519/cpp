#include <iostream>

class base{
public:
virtual void poo(){}
};

class derived : public base{
public:
    void func(){std::cout << "calling func\n";}
};

int main()
{
    base *bptr = new derived;
    bptr->func();//base pointer cannot access derived function func() as bptr is pointing to base class not the derived class so to access the derived class function, dynamic casting is 
    //used which helps in finding out the object's class at runtime.
    derived *dptr = dynamic_cast<derived*>(bptr);
    dptr->func();
    return 0;
}
