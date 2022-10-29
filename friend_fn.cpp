#include <iostream>
#include <string>
#include <random>
#include <cstring>
using namespace std;

class Circle {
private:
    int m_r;

public:
    Circle(int r = 1) {
        m_r = r;
    }
    friend const void printRadius(const Circle &c);
};

const void printRadius(const Circle &c) {
    cout << "radius " << c.m_r;
}

int main(int argc, char **argv) {

    Circle c(5);
    printRadius(c);
} 