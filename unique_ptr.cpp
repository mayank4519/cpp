/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
//#include <memory>

namespace ns
{
    template<class T>

    class unique_ptr{
    private:
      T *m_ptr;
    public:
        unique_ptr(T *ptr = nullptr) :
        m_ptr(ptr)
        {}
        
        ~unique_ptr()
        {
            delete m_ptr;
        }
        /*unique_ptr move(unique_ptr &u)
        {
            m_ptr = u.m_ptr;
            delete u.m_ptr;
            return m_ptr;
        }*/
        
    };
}

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
  
    ns::unique_ptr<resource> res(new resource);
    //std::cout << (static_cast<bool>(res) ? "not null\n" : "null\n");
    
    ns::unique_ptr<resource> res1;
    
    //res1 = ns::unique_ptr::move(res);
    //std::unique_ptr<resource> res1 = res; copy constructor of unique_ptr class is deleted.Shallow copy, making copies of pointers.
    //res1 = res; assignment operator of unique_ptr class is deleted.    
    //res1 = std::move(res);//move semantics
    //std::cout << (static_cast<bool>(res1) ? "not null\n" : "null\n");
        
    return 0;
}
