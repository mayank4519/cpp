#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int increment(int a) {return a+1;}
int add(int a, int b) { return a+b;}
int main() {

    vector<int> v = {1,2,3,4,5};
    vector<int> v1 = {1,2,3,4,5};

    transform(v.begin(), v.end(), v.begin(), increment); // unary fn

    for(auto x : v ) {
        cout << x << " ";
    }
    cout << "\n";
    transform(v.begin(), v.end(), v1.begin(), v1.begin(), add); //binary fn

    for(auto x : v1 ) {
        cout << x << " ";
    }
    cout << "\n";

    transform(v.begin(), v.end(), v1.begin(), v1.begin(), [](int a, int b) {return a+b;}); //using lambda
    for(auto x : v1 ) {
        cout << x << " ";
    }
    cout << "\n";

 }