#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

bool isPalindrome(string str) {
    int s = 0, end = str.size()-1;
    while(s <= end) {
        if(str[s] != str[end]) {
            return false;
        }
        s++, end--;
    }

    return true;
}

vector<vector<string>> getAllParts(string s, vector<string>& partitions, vector<vector<string>> &ans) {
    if(s.size() == 0) {
        ans.push_back(partitions);
    }

    for(int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i+1);
        if(isPalindrome(part)) {
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions, ans);

            partitions.pop_back();
        }
    }

    return ans;
}

int main() {
    string s = "aab";
    vector<vector<string>>ans;
    vector<string> partitions;

    ans = getAllParts(s, partitions, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " "; 
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}