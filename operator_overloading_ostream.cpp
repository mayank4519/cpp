#include<iostream>

class Something{
private:
   int m_x,m_y,m_z;
public:
   Something(int x, int y , int z) :
    m_x(x),m_y(y), m_z(z)
    {}
    
    friend std::ostream& operator<<(std::ostream &out, Something& some);

};

std::ostream& operator<<(std::ostream &out, Something &some)
{
    out << some.m_x << some.m_y << some.m_z;
    
    return out;
}

int main()
{
    Something some(2,3,4);
    std::cout << some;
    return 0;
}