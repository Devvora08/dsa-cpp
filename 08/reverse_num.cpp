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

int main() {
    cout << rev_num(1234) << endl;

    return 0;
}