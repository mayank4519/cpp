#include <iostream>
#include<cstring>
using namespace std;

char* removeDuplicate(char *str,char *rem)
{
    int idx1=0;
    int idx2=0;
    char ch;
    int arr[255] = {0};
    while(*(rem+idx1))
    {
        ch = *(rem+idx1);
        arr[ch] = 1;
        idx1++;
    }
    idx1 = 0;
    while(*(str+idx1))
    {
         ch = *(str+idx1);
        if(arr[ch] == 0)
        {
            *(str+idx2) = *(str+idx1);
            idx2++;
        }
        idx1++;
    }
    *(str+idx2) = '\0';
    return str;
}

int main()
{
   char src[] = "mayankjain";
   char rem[] = "mask";
   cout << src << endl;
   cout << rem << endl;
   cout << removeDuplicate(src,rem);
    return 0;
}