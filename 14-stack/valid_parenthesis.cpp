#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Example 1:

// Input: s = "()"
// Output: true

bool isValid(string s) {
    if(s.length() == 1) return false;

    stack<char> st;
    int idx = 0;
    while(idx < s.length()) {
        if(s.at(idx) != ')' && s.at(idx) != '}' && s.at(idx) != ']') {
            st.push(s.at(idx));
        }
        else {
            if(st.size() == 0) return false;
            if((st.top() == '(' && s.at(idx) == ')') ||
               (st.top() == '[' && s.at(idx) == ']') ||
               (st.top() == '{' && s.at(idx) == '}')
            ) st.pop();
            else return false;
        }
        idx++;
    }
    return st.empty();
}

int main() {
    string s = "{{}([())}";
    string s_two = "({{{[]}}}[])";

    cout << isValid(s) << endl;
    cout << isValid(s_two) << endl;

    return 0;
}