/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory>

template<class T>
class smart_ptr{
private:
    T *m_ptr;
public:
    smart_ptr(T *p = nullptr) :
    m_ptr(p)
    {}
    ~smart_ptr()
    {
        delete m_ptr;
    }
    T& operator*(){return *m_ptr;}
};


int main()
{
    smart_ptr<int> p = new int();
    *p = 200;
    std::cout <<  *p << std::endl;
    return 0;
}
