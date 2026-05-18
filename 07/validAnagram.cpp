#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char, int> characters;

    for(char c : s) {
        characters[c]++;
    }
    // compare 
    for(char c : t) {
        characters[c] --;
        if(characters[c] < 0) return false;
    }

    return true;
}

int main() {
    string a = "devv";
    string b = "veda";

    cout << isAnagram(a,b) << endl;

    return 0;
}