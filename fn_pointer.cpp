#include <iostream>
using namespace std;
void A() {cout << "A\n";}
void B(void (*ptr)()) {(*ptr)();}

int main() {
    void (*fptr)() = &A;

    B(fptr);
}