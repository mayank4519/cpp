#include <iostream>
#include <string>
#include <random>
#include <cstring>
using namespace std;

class base {
    int a;
public:
    int b;
    virtual void fn_base() {
        cout << "im base\n";
    }
protected:
    int c;
    void fn_base_protected() {
        cout << "im base protected\n";
    }
};

class derived : public base {
private:
    void fn() {
        cout << c;
    }
public:
    void print() {
        b = 10, c = 100;
        cout << b << c << endl;
    }
    void fn_base() {
        cout << "im derived\n";
    }
};

int main(int argc, char **argv) {

    derived d;
    base *b;
    b = &d;

    b->fn_base();

    return 0;
}
