#include <iostream>
#include<string>
using namespace std;

class Reverse{
    public:
    void reverseString(string str)
    {
        if(str.length() < 1)
        {
            
        }
            //cout << "null";
        else
        {
            cout << str.at(str.length()-1);
            reverseString(str.substr(0,str.length()-1));
        }
    }
};
int main()
{
    string str = "mayankjain";
    Reverse rev;
    rev.reverseString(str);
    return 0;
}