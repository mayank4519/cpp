#include <iostream>
#include<string>
using namespace std;

int main()
{
   string src = "ABCD";
    string src1 = "CDAB";
   string temp = src + src;
   if(temp.find(src1) != -1)
   {
       cout << "round off\n";
   }
   else
        cout << "no";
    return 0;
}