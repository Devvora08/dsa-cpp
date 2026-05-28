#include <iostream> 
#include <vector>
#include <list>

using namespace std;

// using array/vector
class Stack {
    public:
    vector<int> nums;
    //int top = -1; // initialize the top to -1 - means stack empty

    void push_top(int val) {
        nums.push_back(val);
    }

    void pop() {
        nums.pop_back();
    }

    int top() { // element at top
        return nums[nums.size()-1];
    }

    bool empty() {
        return nums.size() == 0;
    }
};

// using linkedlist
class Stack_With_List {
    public:
    list<int> ll;
    
    void push(int val) {
        ll.push_front(val);
    }
    void pop() {
        ll.pop_front();
    }
    int top() {
        return ll.front();
    }

    bool empty() {
        return ll.empty();
    }
};



int main() {
    // basics of stack
    Stack s;
    
    s.push_top(10);
    s.push_top(20);
    s.push_top(30);
    s.push_top(40);
    s.push_top(50);

    // while(!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    Stack_With_List sl;

    sl.push(5);
    sl.push(15);
    sl.push(25);
    sl.push(45);
    
    while(!sl.empty()) {
        cout << sl.top() << " ";
        sl.pop();
    }
    cout << endl;

    return 0;
}