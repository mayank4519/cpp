#include <iostream>
#include <memory>

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
    std::shared_ptr<base> bptr = std::make_shared<derived>();

    std::shared_ptr<derived> dptr = std::dynamic_pointer_cast<derived>(bptr);
    dptr->func();
    return 0;
}