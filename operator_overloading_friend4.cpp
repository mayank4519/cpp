#include <iostream>

class Fraction{
private:
   int m_num;
   int m_den;
public:
   Fraction(int num,int den):
   m_num(num),m_den(den)
   {}
   
   friend Fraction operator*(const Fraction& f1, const Fraction& f2);
   friend Fraction operator*(Fraction& f1, int x);
   friend Fraction operator*(int x, Fraction& f1);
   friend std::ostream& operator<<(std::ostream& out , Fraction& f);
   

   int reduce(int x, int y) // Find GCD
   {
       return (y == 0) ? x : reduce(y,x%y);
   }
   
   int print()
   {
       int gcd = reduce(m_num,m_den);
       m_num /= gcd;
       m_den /= gcd;
       std::cout << m_num << "/" << m_den << std::endl;
   }
};

std::ostream& operator<<(std::ostream& out , Fraction& f)
{
    out << f.m_num << "/" << f.m_den;
    return out;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
     return Fraction((f1.m_num * f2.m_num), (f1.m_den * f2.m_den));
}

Fraction operator*(Fraction& f1, int x)
{
    return Fraction(f1.m_num*2,f1.m_den);
}

Fraction operator*(int x, Fraction& f1)
{
    return operator*(f1,x);
}

int main()
{
    Fraction f1(2,6);
    std::cout << f1;
    f1.print();

    Fraction f2(5,9);
    f2.print();
    
    Fraction f3 = f1 * f2;
    f3.print();
    
    Fraction f4 =  Fraction(1,2) * Fraction(3,4) * Fraction(4,5);
    f4.print();
    
    return 0;
}