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
   
};


int main()
{
   auto ptr = std::make_unique<resource>();
   std::unique_ptr<resource> uptr = std::make_unique<resource>();
   std::shared_ptr<resource> sptr = std::make_shared<resource>();
    return 0;
}
