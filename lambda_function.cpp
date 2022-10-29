#include <iostream>
#include<vector>
#include<algorithm>

void print(int x)
{
    std::cout << x;
}

int main()
{
    std::vector<int> v = {1,2,3,4,5};
    //for_each(v.begin(), v.end(), [](int i){std::cout << i;}); // for-each loop using lambda function with auto deduce the return type.
    for_each(v.begin(), v.end(), [](int i)->int {std::cout << i;}); //lambda finc implemenatation with explicit return type.
    
    //example 2:
    [](int a){std::cout << a;}(4);
    
    
    return 0;
}