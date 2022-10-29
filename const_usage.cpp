#include <iostream>
using namespace std;

int main() {

    int x = 10, y = 20;
    const int *ptr = &x; // pointer to const int
    //*ptr = 30; // illegal cannot change value of const int

    int *const ptr1 = &y; // const pointer to not constant int
    *ptr1 = 40; // legal
    //ptr1 = &x; // illegal as ptr is constant
    
    const int *const ptr2 = &x; // const ptr to const int
    //ptr2 = &y; // illegal
    //*ptr2 = 300; // illegal

//constexpr requires value at compilation but cosnt doesnt
//constexpr int a; // illegal
constexpr int a = 1; // legal
int size;
const int b = size; //legal
//constexpr int c = size; //illegal as value is requied during compilation

}