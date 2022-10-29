#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    int x = 10;
    int &l = x; // l-value reference intialize with modifiable l-values
    
    
    const int y = 100;
    //int &l1 = y; // l-value reference cannot be intialize with const l-values
    
    // int &l2 = 100; // l-value reference cannot be intialize with r-value
    
    // ----------
    const int &l3 = x; // const l-value reference intialize with modifiable l-values
    
    const int &l4 = 100; // const l-value reference can be intialize with r-value
    
    const int &l5 = y; // const l-value reference can be intialize with const l-values
    
    // ------------
    // C++11 adds a new type of reference called an r-value reference. 
    // An r-value reference is a reference that is designed to be initialized with an r-value (only).
    int &&r = 100;
    
    // r value reference cannot be initialized or modifiable with modifiable or non modifiable l value referernces
    // int &&r1 = x;
    
    // int &&r2 = y;
    
    return 0;
}