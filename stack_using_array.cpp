
#include <iostream>
#define MAX 100
using namespace std;

class Stack{
private:
    int top;
public:
    int arr[MAX];
    Stack() : top(-1)
    {}
     bool push(int x)
    {
        if(top >= MAX-1)
        {
            cout << "stackoverflow\n";
            return false;
        }
        arr[top+1] = x;
        top = (top+1)%MAX;
    }
    bool pop()
    {
        if(top == -1)
        {
            cout << "stack is empty\n";
            return false;
        }
        top--;
    }
    void print()
    {
        for(int i=0 ; i<=top ; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Stack stk;
    stk.push(10);
        stk.push(20);
    stk.push(30);

    stk.print();
    return 0;
}
