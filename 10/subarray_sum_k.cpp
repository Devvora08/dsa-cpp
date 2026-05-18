#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

int optimal(vector<int> &nums, int k) {
    // create prefix sum array, use unordered hashmap
    vector<int> pref(nums.size(), 0);
    int count = 0;
    unordered_map<int,int> m;

    pref[0] = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        pref[i] = pref[i-1] + nums[i];
    }
    m[0] = 1;

    for (int j = 0; j < nums.size(); j++) {

        if (m.find(pref[j] - k) != m.end()) {
            count += m[pref[j] - k];
        }

        m[pref[j]]++;
    }

    return count;
} 

int brute_force(vector<int> &nums, int k) {
    // approach - find all subarray sums, if sum = k, add to count - O(n^2) TC
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        int current_sum = 0;
        for(int j = i; j < nums.size(); j++) {
            current_sum += nums[j];
            if(current_sum == k) count++;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << optimal(nums, k) << endl;

    return 0;
}