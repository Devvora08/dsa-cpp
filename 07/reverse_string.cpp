#include <vector>
#include <iostream>

using namespace std;

// reverse array without using extra space. in place.
void reverse_char_array(vector<char> &s) {
    // use 2 pointer approach to swap
    int i = 0;
    int j = s.size() - 1;

    while(i <= j) {
        swap(s[i],s[j]);
        i++;
        j--;
    }

    for(char i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<char> s = {'h','e','l','l','o'};
    for(char i : s) {
        cout << i << " ";
    }
    cout << endl;

    reverse_char_array(s);

    return 0;
}