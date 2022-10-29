#include <iostream>
#include <string>
int main()
{
    int x;
    std::cin >> x;
    std::cout << x;
    std::cin.ignore(32767,'\n');
    std::string mj;
    std::getline(std::cin, mj);
    std::cout << " " << mj;

    return 0;
}