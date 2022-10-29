#include <iostream>
#include <string>
#include <random>
#include <cstring>
using namespace std;

class base {
    int a;
public:
    int b;
    void fn_base() {
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
};

int main(int argc, char **argv) {

    derived d;
    d.print();
    d.fn_base();
    //d.fn_base_protected(); // not accessible
    return 0;
}
