#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

using _fptr = int(*)(int);

int multiply(int x) {return x*x;}

int fptr_callback(vector<int> &v, _fptr arg) 
{
    for(int i=0;i<v.size();i++) {
        v[i] = arg(v[i]);
    }
}

int main() {
    vector<int> v = {1,2,3,4,5};
    fptr_callback(v, multiply);

    for(auto x : v ) {
        cout << x << " ";
    }
    cout << "\n";

}