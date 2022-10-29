#include <iostream>
#include <string>
int main()
{
    std::string src = "mayank jain";
    std::string dst(src,3,5);//starting from 3 print 5 chars.
    std::cout << dst;
    //dst(src,3,5);
    return 0;
}
