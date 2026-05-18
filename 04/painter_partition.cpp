#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &arr, int n, int m, int min_time) {
    int painters = 1;
    int boards = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > min_time) return false;

        if(boards + arr[i] <= min_time) {
            boards += arr[i];
        } else {
            painters ++;
            boards = arr[i];
        }
    }
    
    return painters > m ? false : true;
}

int allocate_paint(vector<int> &arr, int n, int m) {
    if(m > n) return -1;

    int sum = 0;
    int max_board_len = INT32_MIN;
    for(int i : arr) {
        sum += i;
        max_board_len = max(max_board_len, i);
    }

    int st = max_board_len;
    int end = sum;

    int min_time = -1;

    while(st <= end) {
        int mid = st + (end-st)/2;

        if(isValid(arr, n, m, mid)) {
            min_time = mid;
            end = mid-1;
        } else {
            st = mid+1;
        }
    }

    return min_time;
}

int main() {
    vector<int> arr = {40,30,10,20};
    int n = 4;
    int m = 2; 

    cout << allocate_paint(arr, n, m) << endl;

    return 0;
}