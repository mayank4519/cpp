/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void func(int *ptr)
{
    //int y=10;
    //ptr = &y;
    ptr = nullptr;
}

int main()
{
    cout<<"Hello World";
    int x = 5;
    int *ptr = &x;
    cout << *ptr ;
    func(ptr);
    cout << *ptr;

    return 0;
}