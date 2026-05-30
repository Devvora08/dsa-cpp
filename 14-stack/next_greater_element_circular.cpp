#include <vector>
#include <iostream>
#include <stack>

using namespace std;
// variation of next greater element but using a cyclic array

vector<int> nextGreaterElements(vector<int>& nums) {
    // approach - simulate nums .. nums 2 times linear way using indexing and iteration
    vector<int> ans(nums.size());
    int n = nums.size();
    stack<int> s;

    for(int i = 2*n-1; i >= 0; i--) {
        while(s.size() > 0 && s.top() <= nums[i%n]) {
            s.pop();
        }
        if(s.empty()) ans[i%n] = -1;
        else ans[i%n] = s.top();

        s.push(nums[i%n]);
    }

    return ans;
}

int main() {
    vector<int> nums = {3,6,5,4,2};
    vector<int> ans = nextGreaterElements(nums);

    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}