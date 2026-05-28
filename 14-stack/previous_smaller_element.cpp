#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Smaller Element (PSE).

// The Previous Smaller Element (PSE) of an element x is the first element that appears to the left of x in the array and is strictly smaller than x.
// Note: If no such element exists, assign -1 as the PSE for that position.

vector<int> previousSmallerElement(vector<int> &nums) {
    // same approach as nge, but opposite
    vector<int> ans(nums.size(), 0);
    int n = nums.size();
    stack<int> s;

    for(int i = 0; i < n; i++) {
        while(s.size() > 0 && s.top() >= nums[i]) {
            s.pop();
        }
        if(s.size() == 0) {
            ans[i] = -1;
        } else ans[i] = s.top();
        s.push(nums[i]);
    }

    return ans;
}

int main() 
{
    vector<int> nums = {3,1,0,8,6};
   
    vector<int> ans = previousSmallerElement(nums);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}