#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

//functors are func objects and can be implemented by overloading operator()

class increment{
int m_num;
public:
    increment(int x) : m_num(x){}

    int operator()(int a, int b) {return a + b  + m_num;}
};

int main() {
    vector<int> v = {1,2,3,4,5};
    vector<int> v1 = {1,2,3,4,5};
    increment obj(5);

    transform(v.begin(), v.end(), v1.begin(), v1.begin(), obj);

    for(auto x : v1 ) {
        cout << x << " ";
    }
    cout << "\n";
}