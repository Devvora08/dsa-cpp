#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Return the maximum possible minimum distance.

// Ex :
// n = 3
// k = 2
// arr = {1,2,3}
// answer = 2
// Explanation - The max possible min distance will be 2 when 2 cows are placed at positions {1,3}. Here distance between cows is 2.

bool isMin(vector<int>& pos, int n, int c, int minDis) {
    int cows = 1;
    int lastStallPos = pos[0];

    for(int i = 0; i < n; i++) {
        if(pos[i] - lastStallPos >= minDis) {
            cows++;
            lastStallPos = pos[i];
        } 
        if(cows == c) return true;
    }

    return false;
}

int agressive_cows(vector<int>&pos, int n, int c) {
    // sort the array first
    sort(pos.begin(), pos.end());

    if(c > n) {
        return -1;  // cows cant be greater than the postions available
    }

    int possible_ans = -1;

    int s = 1, end = pos[n-1]-pos[0];
    while(s <= end) {
        int mid = s + (end-s)/2;

        if(isMin(pos, n, c, mid)) {
            possible_ans = mid;
            s = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return possible_ans;
}

int main() {
    int n = 5;
    vector<int> pos = {2,4,6,8,9};
    int c = 3;

    // range from s and end -> s = (2nd smallest - smallest) ~1, end = (largest - smallest)
    // here s = least distance, e = most distance, we tend to go to right

    int min_ans = agressive_cows(pos, n, c);
    cout << min_ans << endl;

    return 0;
}