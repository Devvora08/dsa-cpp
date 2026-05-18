#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

bool isAlphanumeric(char c) {
    if((c >= '0' && c <= '9') || (tolower(c) <= 'z' && tolower(c) >= 'a')) return true;

    return false;
}

bool isPalindrome(string s)
{
    // alphanumeric = a-z,A-Z, 0-9
    // approach - skip elements that are non alphanumeric
    int i = 0; 
    int j = s.length() - 1;

    while(i < j) {
        if(!isAlphanumeric(s[i])) {
            i++;
            continue;
        }
        if(!isAlphanumeric(s[j])) {
            j--;
            continue;
        }

        if(tolower(s[i]) != tolower(s[j])) return false;
        i++; 
        j--;
    }
    return true;
}

int main()
{
    // string i = "   we2  afwr    ";
    string s = "A man, a plan, a canal: Panama";    

    cout << isPalindrome(s) << endl;

    return 0;
}