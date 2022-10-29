#include <iostream>
#include <string>

using namespace std;

class reverseword
{
public:
       void rev_words(char *str)
       {
           char *temp = str;
           char *begin = str;
           while(*temp)
           {
               temp++;
               if(*temp == '\0')
               {
                   reverse(begin, temp-1);
               }
                else if(*temp == ' ')
                {
                    reverse(begin,temp-1);
                    begin = temp+1;
                }
               // temp++;
           }
           cout << str << endl;
           reverse(str,temp-1);
       }
       
       void reverse(char *begin, char *end)
       {
           char ch;
            while(begin < end)
            {
                ch = *begin;
                *begin = *end;
                *end = ch;
                begin++;
                end--;
            }
       }
};

int main()
{
    char str[] = "my name is mayank jain";
    cout << str << endl;
    reverseword rev;
    rev.rev_words(str);
    cout << str;
    return 0;
}
