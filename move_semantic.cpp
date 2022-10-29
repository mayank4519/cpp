
#include <iostream>

using namespace std;

class A
{
public:
    // default constructor
    A() : s("default") {}

    // copy constructor
    A(const A& o) : s(o.s) { cout << "move failed!\n";}

    // move constructor
    A(A&& o) : s(move(o.s)) {}

    string printObj() { return s; }
private:
    string s;
};

A temp(A a) {
    return a;
}

int main()
{
    // move-construct from rvalue temporary
    A a1 = temp(A());        

    // move-construct from lvalue 
    cout << "before move() : a1 = " << a1.printObj() << endl; 
    A a2 = move(a1);          
    cout << "after move() : a1 = " << a1.printObj() << endl;
    cout << "after move() : a2 = " << a2.printObj() << endl;

    return 0;
}
