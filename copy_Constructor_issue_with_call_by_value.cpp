/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <assert.h>

class Fraction{
    int m_num;
    int m_den;
public:
    //default constructor
    Fraction(int num=1 , int den = 1) :
    m_num(num) , m_den(den)
    {
        assert(den != 0);
    }
    //copy constructor
    Fraction(Fraction &frac)  = delete;
};
void print(Fraction f)//if we do call by value,copy constructor will get called and it will try to reference a deleted function.
{
    std::cout << "hi";
}

int main()
{
    Fraction f;
    print(f);
    return 0;
}
