#include <iostream>
#include<cstring>
//using namespace std;
int main()
{
   char src[] = "mayankjain";
   int len = strlen(src);
   std::cout << src << std::endl;
   char dst[len+1] = "";
   int arr[255]={0};
   for(int i=0;i<len;i++)
   {
       arr[src[i]]++;
   }
   
   for(int i=0;i<len;i++)
    {
        if(arr[src[i]] >= 1)
        {
            dst[i] = src[i];
            arr[src[i]] = 0;
            std::cout << dst[i];

        }
    }
    return 0;
}