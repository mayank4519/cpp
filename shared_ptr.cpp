#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class A{
int x;
public:
    A(int x) : x(x) {}

    void print() {std::cout << x;}
};

int main() {

    std::shared_ptr<A> p = std::make_shared<A> (10);

    p->print();

    auto x = p;

    std::shared_ptr<A> p1(p); // copy constructor

    std::shared_ptr<A> p2;

    p2 = p;
    p2->print();

    if (p == nullptr)
        std::cout << "u is null";
    return 0;
}