#include <iostream>

class mj{
 public:
    int j;
    static int i;
    mj()
    {
        j = i++;
    }
    int getid(){return j;}
};

int mj::i = 1;//initialise it here

int main()
{
  mj m1;
  mj m2;
  std::cout << m1.getid() << m2.getid() << std::endl;
  std::cout << m1.i << m2.i;
    return 0;
}
