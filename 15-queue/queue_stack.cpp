#include <queue>
#include <iostream>
#include <stack>

using namespace std;

class StackUsingQueue {
    public:
    queue<int> q1;
    queue<int> q2;
    
    StackUsingQueue() {

    }

    void push(int val) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();

        return ans;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

class QueueUsingStacks {
    public:
    stack<int> s1;
    stack<int> s2;

    QueueUsingStacks() {

    }

    void push(int val) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int ans = s1.top();
        s1.pop();

        return ans;
    }

    int front() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    return 0;
}