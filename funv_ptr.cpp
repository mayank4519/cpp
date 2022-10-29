#include <iostream>

void add(int a, int b)
{
    std::cout << a << b;
}

void sub(int a, int b)
{
    std::cout << a << b;
}

int main()
{
    void (*fnPtr_arr[])(int,int) = {add,sub};
    fnPtr_arr[0](10,20);
}