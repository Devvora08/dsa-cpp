#include <vector>
#include <iostream>

using namespace std;

bool armstrong(int n) {
    int copy = n;
    int sum = 0;
    while(n > 0) {
        int digit = n % 10;
        sum += (digit*digit*digit);
        n /= 10;
    }

    return sum == copy;
}

int main() {
    cout << armstrong(113) << endl; 
    return 0;
}