/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Cal{
    int num;
public:
    Cal(): num(0)
    {}
    void set(int x)
    {
        num = x;
    }
    friend void get(Cal &cal);
    
};


void get(Cal &cal)
{
    cout << cal.num;
}
int main()
{
    Cal cal;
    cal.set(2);
    get(cal);
    return 0;
}
