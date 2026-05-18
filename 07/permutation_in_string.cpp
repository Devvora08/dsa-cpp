#include <iostream>
#include <vector>

#include <string>

using namespace std;

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

bool isSame(int freq1[], int freq2[]) {
    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) return false;
    }

    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }
    // freq array created.

    // window method
    int window_size = s1.length();

    for(int i = 0; i < s2.length(); i++) {
        int window_idx = 0, idx = i;
        int window_freq[26] = {0};

        while(window_idx < window_size && idx < s2.length()) {
            window_freq[s2[idx]-'a']++;
            window_idx++;
            idx++;
        }

        if(isSame(window_freq, freq)) return true;
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1,s2) << endl;

    return 0;
}