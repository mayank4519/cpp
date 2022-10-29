#include <iostream>
#include<cstring>
using namespace std;

char* removeDuplicate(char *str)
{
    int arr[255] = {0};
    int idx1=0;
    int idx2=0;
    char ch;
    while(*(str+idx1))
    {
        ch = *(str+idx1);
        if(arr[ch] == 0)
        {
            *(str+idx2) = *(str+idx1);
            idx2++;
            arr[ch] = 1;
        }
        idx1++;
    }
    *(str+idx2) = '\0';
    return str;
}

int main()
{
   char src[] = "mayankjain";
   cout << removeDuplicate(src);
    return 0;
}