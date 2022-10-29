#include <iostream>
#include <string>

using namespace std;

#define SIZE 10

template <class T> class Stack {
public:
    Stack() {
        cout << "stack constructor called\n";
        top = -1;
    }
    ~Stack(){
    }
    
    bool isFull() {
        return (top == SIZE-1)  ? true : false;
    }
    void push(T const& val) {
        if (isFull() == true) {
            cout << "stack is full\n";
        }
        else {
            top++;
            m_stack[top] = val;
        }
    }
    T pop() {
        if (isEmpty() == true)
            return -1;
        else {
            T temp = m_stack[top];
            top--;
            return temp;
        }

    }
    T topElement() {
        return m_stack[top];
    }
    
    bool isEmpty() {
        return (top == -1) ? true : false;
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << m_stack[i] << "\t";
        }
        cout << "\n";
    }

private:
    uint16_t top;
    T m_stack[SIZE];
};