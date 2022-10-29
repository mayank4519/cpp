#include <iostream>
using namespace std;

class Cents{
int m_cents;
public:
    Cents(int m_cents)
    {
        this->m_cents = m_cents;
    }
    int getCents() {return m_cents;}

    // friend Cents operator+(Cents &cent1, Cents &cent2);
    Cents operator+(Cents &cent1);
    friend std::ostream& operator<<(std::ostream &out, Cents &c);
};

std::ostream& operator<<(std::ostream &out, Cents &c)
{
    out << c.m_cents;
    return out;
}

Cents Cents::operator+(Cents &cent1) {
        return Cents(cent1.m_cents + m_cents);
    }

// Cents operator+(Cents &cent1, Cents &cent2) {
//         return Cents(cent1.m_cents + cent2.m_cents);
//     }

int main() {
    Cents c1(1);
    Cents c2(2);
    Cents sum = c1 + c2;
    cout << sum.getCents() << endl;

    cout << sum << c1;
}