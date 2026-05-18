#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i*i < n; i++) {
        if(n % i == 0) return false;
    }

    return true;
}

int countPrimes(int n) {
    vector<bool> isPrime(n+1, true);
    int count = 0;

    for(int i = 2; i<n; i++) {
        if(isPrime[i]) { 
            count++;

            for(int j = i*2; j<n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    return count;
}

int main() {
    // cout << isPrime(18) << endl;
    cout << countPrimes(10) << endl;

    return 0;
}