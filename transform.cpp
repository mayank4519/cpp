#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int increment(int a) {return a+1;}
int main() {

    //std::array<int,5> a {1,2,3,4,5};
    int a[] = {1,2,3,4,5};

    transform(a, a + 5, a, increment);
}