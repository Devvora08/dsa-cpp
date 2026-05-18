#include <vector>
#include <iostream>

using namespace std;

// find the hcf/ greatest common factor between 2 numbers

int optimal_gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    if(a > b) return optimal_gcd(a-b, b);
    return optimal_gcd(a, b-a);
}

int greatest_common_factor(int a, int b) {
    int st = 1;
    int end = min(a,b);

    int gcd = 1;

    for(int i = 1; i <= min(a,b); i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int least_common_multiple(int a, int b) {
    int gcd = optimal_gcd(a,b);

    return (a*b/gcd);
}

int main() {
    cout << greatest_common_factor(20,28) << endl;
    cout << optimal_gcd(20,28) << endl;

    cout << least_common_multiple(5,11)<< endl;

    return 0;
}