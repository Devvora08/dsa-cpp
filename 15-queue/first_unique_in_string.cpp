#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Input: s = "leetcode"
// Output: 0

int uni_char(string s) {
    unordered_map<char, int> m;

    // count frequency
    for(char c : s) {
        m[c]++;
    }

    // find first unique char index
    for(int i = 0; i < s.size(); i++) {
        if(m[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << uni_char("letter") << endl;
    return 0;
}