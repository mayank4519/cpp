#include "Stack_using_template.h"
#include "vector_using_template.hpp"

int main(){
    vector<int> v;
    Stack<int> s;
    s.push(13);
    s.push(10);
    s.push(20);
    s.push(50);
    s.display();
    cout << s.topElement();
    s.pop();
    s.display();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(auto x : v) {
        cout << x << "\t";
    }
    cout << "\n";
    cout << v.size() << "\n";
    cout  << v.getCapacity() << "\n";

    vector<int> v2(v); // copy constructor
    for(auto x : v2) {
        cout << x << "\t";
    }
    cout << "\n";

    vector<int> v1;
    v1 = v; // copy assignment
    for(auto x : v1) {
        cout << x << "\t";
    }
    cout << "\n";
}