#include <vector>
#include <iostream>

using namespace std;

int rev_num(int n) {
    int rev = 0;

    while(n > 0) {
        if(rev > INTMAX_MAX/10 || rev < INT8_MIN / 10) return 0;

        rev *= 10;
        rev += (n%10);
        
        n /= 10;
    }

    return rev;
}

bool isPallindrome(int n) {
    if(n<0) return false;
    return n == rev_num(n);
}

int main() {
    cout << isPallindrome(353) << endl;
    return 0;
}