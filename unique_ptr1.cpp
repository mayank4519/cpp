/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory>

class resource{
 
  public:
    resource()
    {
        std::cout << "resource const is called\n";
    }
     ~resource()
    {
        std::cout << "resource dest is called\n";
    }
    friend std::ostream& operator<<(std::ostream &out , resource &res)
    {
        out << "i am in resource\n";
        return out;
    }
};

//ownership of the Resource was transferred to somefunction(), so the Resource was destroyed at the end of somefunction() rather than the end of main().
void somefunction(auto ptr)
{
    if(ptr)
        std::cout << *ptr;
}

int main()
{
    //make_unique will create a dynamically allocated resource object.No need to use new keyword.Also make_unique will resolve some exception safe issues.
    //std::unique_ptr<resource> res = std::make_unique<resource>(); --> this is also correct.
    auto res = std::make_unique<resource>();
    somefunction(std::move(res));
    
    return 0;
}
