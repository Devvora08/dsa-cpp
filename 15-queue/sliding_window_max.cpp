#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int max_ele(vector<int> &nums,vector<int> &ans) {
    int maxE = -100;
    for(int i : nums) {
        if(i >= maxE) {
            maxE = i;
        }
    }
    return maxE;
}

vector<int> sliding(vector<int>&arr, int k) {
    
    vector<int> ans;
    for(int i = 0; i <= arr.size()-k; i++) {
        vector<int> nums;
        for(int j = i; j < i+k; j++) {
            nums.push_back(arr[j]);
        }
        ans.push_back(max_ele(nums, ans));
    }

    return ans;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq;

    // store first window elements
    for(int i = 0; i < k; i++) {
        // pop lesser elements than ith
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // remaining window array
    for(int i = k; i < nums.size(); i++) {
        result.push_back(nums[dq.front()]);

        // remove previous window indexes
        while(dq.size() > 0 && dq.front() <= i-k) {
            dq.pop_front();
        }

        while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    result.push_back(nums[dq.front()]);

    return result;
}

int main() {
    vector<int> ans;
    vector<int> arr = {1,3,-1,-3,5,3,6,7};

    ans = maxSlidingWindow(arr, 3);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}