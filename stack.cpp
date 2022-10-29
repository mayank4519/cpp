
#include <iostream>
#include<stack>
using namespace std;

void print(stack<int> stk)
{
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
}

int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    print(stk);
    cout << stk.size();
    return 0;
}