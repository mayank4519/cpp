#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int multiply(int x) {return x*x;}

int fptr_callback(vector<int> &v, int(*fptr)(int)) 
{
    for(int i=0;i<v.size();i++) {
        v[i] = fptr(v[i]);
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