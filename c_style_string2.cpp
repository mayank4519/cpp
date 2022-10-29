#include <iostream>
#include <cstring>
int main()
{
   char arr[255];//declare c-style string to hold max 255 chars
   std::cin.getline(arr, 255);//making sure only 254 chars are allowed and one for null termination.To make sure there is no extra character
   //after 254
   std::cout << arr << " ";

    std:: cout << "arr has " << strlen(arr) << " characters\n"; 
    std::cout << "arr has " << sizeof(arr)/sizeof(arr[0]) << " character size\n"; 
    return 0;
}