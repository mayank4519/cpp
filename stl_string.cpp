#include <iostream>
#include <string>
int main()
{
    std::string mj = "mayank";
    std::cout << mj.length();
    for(int i=0;i< mj.length(); i++)
    {
        std::cout << static_cast<int>(mj[i]) << " ";
    }

    return 0;
}