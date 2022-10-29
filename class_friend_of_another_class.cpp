/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Storage{
  int x;
  public:
  Storage(): x(99)
  {}
  friend class Display;
};

class Display{
    public:
    void get(Storage &storage)
    {
        cout << storage.x;
    }
};

int main()
{
    Storage storage;
    Display disp;
    disp.get(storage);
    return 0;
}
