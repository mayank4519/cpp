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
    Fraction(Fraction &frac) : //we can't do pass by value for copy constructor bcoz it will call copy constructor recursively.
    m_num(frac.m_num) , m_den(frac.m_den)
    {}
    
    friend std::ostream& operator<<(std::ostream &out, Fraction frac);
};

std::ostream& operator<<(std::ostream &out, Fraction frac)
//However, if you try to return std::ostream by value, you’ll get a compiler error.By value will call the copy constructor which is protected & deleted in std::ostream class.
{
    out << frac.m_num << "/" << frac.m_den;
    return out;
}

int main()
{
    Fraction frac{5,3};
    Fraction fcopy(frac); // copy constructor is called.It uses member intialization that means fcopy will initialise 
//m_num n m_den with the members of object being passed in copy constructor.    
    std::cout << frac  << fcopy;// std::cout is an object of std::ostream
    return 0;
}
