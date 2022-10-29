#include <iostream>

class Calculator{
private:
  int m_val;
  
public:
  Calculator()
  {
      m_val = 0;
  }
  
   Calculator& add(int x){m_val += x; return *this;}
   Calculator& sub(int x){m_val -= x; return *this;}
   Calculator& mult(int x){m_val *= x; return *this;}
   
   int getValue(){return m_val;}
};
int main()
{
    Calculator cal;
    cal.add(5).sub(2).mult(3);
    std::cout << cal.getValue();
    return 0;
}