#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string st) {
    // helper function - (O[n]) - TC
    int s = 0, end = st.size()-1;
    while(s < end) {
        if(st[s] != st[end]) return false;
        s++, end--;
    }
    return true;
}

string longest_substring_brute_force(string st) {
    // check if entire string is pallindrome
    if(isPalindrome(st)) return st;

    int max_substring_palindrome = 1;
    string ans = st.substr(0,1);
    for(int i = 0; i < st.size(); i++) {
        string result = "";
        for(int j = i; j < st.size(); j++) {
            result += st[j];
            if(isPalindrome(result)) {
                if((int)result.size() > max_substring_palindrome) {
                    max_substring_palindrome = max(max_substring_palindrome, (int)result.size());
                    ans = result;
                } 
            }
        }
    }

    return ans;
}

int main() {
    string st = "bab";

    cout << longest_substring_brute_force(st) << endl;

    return 0;
}