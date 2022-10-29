#include <iostream>

class mj{
 public:
    //static int i=10; C++ forbids in-class initialization of non-const static member ‘mj::i’
    static int i;
mj()
{}
};

int mj::i = 10;//initialise it here

int main()
{
  mj m1;
  //m1.i = 2;//cannot create copy of static variable i using multiple objects.
  //m2.i = 3;//
  std::cout << m1.i;

    return 0;
}
