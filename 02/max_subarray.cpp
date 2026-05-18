#include <iostream> 
#include <vector>
using namespace std;

int main() {
    int n = 7;
    // int arr[n] = {1,2,3,4,5};
    int arr[] = {1,-5,3,18,-20,4,5};
    int maxSum = INT16_MIN;

    // brute force - O n^3
    for(int st = 0; st < n; st++) {
        for(int end = st; end<n; end++) {
            int currentSum = 0;
            for(int i = st; i <= end; i++) {
                currentSum+= arr[i];
                cout << arr[i];
            }
            maxSum = max(maxSum, currentSum);
            cout << " ";
        }
        cout << endl;
    }

    // optimied - O n^2
    for(int st = 0; st < n; st++) {
        int currenSum = 0;
        for(int end = st; end<n; end++) {
            currenSum += arr[end];
        }
        maxSum = max(maxSum, currenSum);
        cout << " ";
        cout << endl;
    }

    // Kadane's algorithm = O(n)
    int current = 0;
    for(int i = 0; i < n; i++) {
        current += arr[i];
        maxSum = max(current, maxSum);
        if(current < 0) {
            current = 0;
        }
    }
    cout << "max sum subarray : " << maxSum << endl;

    return 0;
}