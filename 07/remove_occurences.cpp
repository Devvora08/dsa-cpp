#include <iostream>
#include <vector>

#include <string>

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"

using namespace std;

string removeOccurrences(string s, string part) {
    // use string.find, string.erase functions
    while(s.find(part) < s.length()) {
        int idx = s.find(part);
        s.erase(idx, part.length());
    }

    return s;
}

int main() {
    string s = "axxxxyyyyb";
    string part = "xy";

    cout << removeOccurrences(s,part) << endl;

    return 0;
}