#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
vector<int> nge(vector<int>&nums) {
    vector<int> ans(nums.size(), 0);
    stack<int> s;
    int n = nums.size()-1;

    for(int i = n; i >= 0; i--) {
        while(s.size() > 0 && s.top() <= nums[i]) {
            s.pop();
        }
        if(s.size() == 0) ans[i] = -1;
        else ans[i] = s.top();
        s.push(nums[i]);
    }

    return ans;
}
// nums1 = 4,1,2 nums2 = 1,3,4,2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // same approach, but through 2 arrays
    stack<int> s;
    unordered_map<int, int> m;
    int n = nums2.size()-1;

    // create map for main array
    for(int i = n; i >= 0; i--) {
        while(s.size() > 0 && s.top() <= nums2[i]) {
            s.pop();
        }
        if(s.size() == 0) {
            m[nums2[i]] = -1;
        }
        else m[nums2[i]] = s.top();
        s.push(nums2[i]);
    }

    vector<int> ans;
    for(int i = 0; i < nums1.size(); i++) {
        ans.push_back(m[nums1[i]]);
    }

    return ans;
}

int main() {
    vector<int> nums = {6,8,0,1,3};
    vector<int> nums2 = {1,3,0};
    vector<int> ans = nge(nums); 
    //vector<int> ans = nextGreaterElement(nums2, nums);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}