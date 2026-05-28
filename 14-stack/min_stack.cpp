#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

class MinStack {
public:
    stack<int> s;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(minStack.top() == s.top()) minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    return 0;
}