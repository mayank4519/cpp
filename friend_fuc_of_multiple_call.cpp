/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Mal; // if this is not deinfed here then compiler will give error in friend func of Cal that Mal class is not present.

class Cal{
    int num;
public:
    Cal(): num(0)
    {}
    void set(int x)
    {
        num = x;
    }
    friend void get(Cal &cal,Mal &mal);
    
};

class Mal{
  int mj;
  public:
  Mal(): mj(10)
  {}
  friend void get(Cal &cal,Mal &mal);
};

void get(Cal &cal,Mal &mal)
{
    cout << cal.num << "" << mal.mj;
}

int main()
{
    Cal cal;
    cal.set(2);
    Mal mal;
    get(cal,mal);
    return 0;
}
