#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

//functors are func objects and can be implemented by overloading operator()

class increment{
int m_num;
public:
    increment(int x) : m_num(x){}

    int operator()(int num) {return num  + m_num;}
};

int main() {
    vector<int> v = {1,2,3,4,5};
    increment obj(5);

    transform(v.begin(), v.end(), v.begin(), obj);

    for(auto x : v ) {
        cout << x << " ";
    }
    cout << "\n";
}