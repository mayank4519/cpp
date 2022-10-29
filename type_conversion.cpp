#include<iostream>
using namespace std;
static void function(float);
void function(int);
static void function(float x)
{
std::cout << "Value of x is : " <<x<< std::endl;
}
void function(int y)
{
std::cout << "Value of y is : " <<y<< std::endl;
}
int main()
{
function(3.4f);
function(34);
return 0;
}