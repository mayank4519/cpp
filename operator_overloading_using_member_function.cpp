
#include <iostream>

class Cents{
private:
  int m_cents;
  
public:
  Cents(int m_cents)
  {
      this->m_cents = m_cents;
  }
  
  int getCents(){return m_cents;}
  
 //friend Cents operator+(Cents& c1,Cents& c2);
  Cents operator+(Cents &c2); // operator(Cents &c1, ){return *this}
};

Cents Cents::operator+(Cents& c2)
{
    return Cents(m_cents + c2.m_cents);    
}


int main()
{
    Cents cent1(5);
    Cents cent2(6);
    Cents sumcent = cent1 + cent2; // cent1.operator+(cent2) becomes operator(&cent1,cent2);
                                 //   So basically cent1 becomes a hidden this pointer
    std::cout << sumcent.getCents();

    return 0;
}