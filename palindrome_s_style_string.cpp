#include <iostream>
#include <cstring>
int main()
{
    char src[255 ];
    std::cin.getline(src,255);
    int len = strlen(src);
    std::cout << len << std::endl;
    bool flag = false;
    for(int i=0;i<len;i++)
    {
        if(src[i] == src[len-1-i])
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }
    flag ?  std::cout << "yes palindrome\n" : std::cout << "not a palindrome\n";

    return 0;
}
