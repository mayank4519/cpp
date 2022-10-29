#include<iostream>

class Cents{
  private:
  int m_cents;
  
  public:
  Cents(int m_cents)
  {
      this->m_cents = m_cents;
  }
  
  int getCents(){return m_cents;}
  
 friend Cents operator+(Cents& c1,Cents& c2);
};

Cents operator+(Cents& c1,Cents& c2)
{
    return Cents(c1.m_cents + c2.m_cents);    
}

int main()
{
    Cents cent1(5);
    Cents cent2(6);
    Cents sumcent = cent1 + cent2;
    std::cout << sumcent.getCents();
    return 0;
}