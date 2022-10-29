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


int main()
{
    std::shared_ptr<resource> res1 = std::make_shared<resource>();//shared_ptr is pointing to resource Object pointer.
    {
        auto res2 = res1;
    }
    return 0;
}
