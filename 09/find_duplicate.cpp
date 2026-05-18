#include <iostream>
#include <vector> 
#include <set>

using namespace std;

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

// Example 1:

// Input: nums = [3,1,2,4,2]
// Output: 2

int cyclicSort(vector<int> &nums) {
    // sort using cyclic sort = O(N) -> in place method
    int n = nums.size();
    int i = 0;
    while(i < n) {
        int correctIdx = nums[i] - 1;
        if(nums[correctIdx] != nums[i]) {
            swap(nums[correctIdx], nums[i]);
        } else i++;
    }

    for(int j = 0; j < n; j++) {
        if(j != nums[j]-1) {
            return nums[j];
        }
    }

    return -1;
}

int useSet(vector<int> &nums) {
    // use set, add val till find duplicate
    set<int> s;
    for(int i = 0; i < nums.size(); i++) {
        if(s.find(nums[i]) != s.end()) return nums[i];

        s.insert(nums[i]);
    }

    return -1;
}

int findDuplicate(vector<int>& nums) {
    // use 2 pointer approach --> 2 steps
    // nums = [3,1,2,4,2]
    int fast = nums[0], slow = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    slow = nums[0];

    while(fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow; // or nums[fast] as fast == slow
}

int main() {
    vector<int> nums = {2,1,2,4,5};

    cout << findDuplicate(nums) << endl;

    return 0;
}