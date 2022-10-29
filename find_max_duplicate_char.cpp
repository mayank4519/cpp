#include <iostream>
#include<cstring>
//using namespace std;
int main()
{
   char src[] = "abbcccddddeeeee";
   int arr[255]={0};
    int len = strlen(src);
   for(int i=0;i<len;i++)
   {
       arr[src[i]]++;
   }
   int max=-1;
   char res;
    for(int i=0;i<len;i++)
    {
        if(arr[src[i]] > max)
        {
            max = arr[src[i]];
            res = src[i];
        }
    }
    std::cout << res;
    return 0;
}