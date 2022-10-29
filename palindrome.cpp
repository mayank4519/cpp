#include <iostream>
#include <string>
int main()
{
    std::string src;
    std::cin >> src;
    std::cout << src.length();
    bool flag = false;
    for(int i=0;i<src.length();i++)
    {
        if(src[i] == src[src.length()-1-i])
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