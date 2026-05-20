#include <iostream>
#include <vector> 

using namespace std;

void combination_sum(vector<int> &nums,vector<int> &ans,int i, int target, vector<vector<int>>& result) {
    // base cases
    if(target == 0) {
        result.push_back(ans);
        return;
    }

    if(i == nums.size() || target < 0) return;

    // 2 recursive calls
    ans.push_back(nums[i]);
    combination_sum(nums, ans, i, target - nums[i], result);

    // backtrack
    ans.pop_back();

    // exclude current element
    combination_sum(nums, ans, i + 1, target, result);
}

int main() {
    vector<int> nums = {2,3,5};
    vector<vector<int>> result;
    vector<int> ans;

    combination_sum(nums, ans, 0, 7, result);

    for(int i = 0; i< result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}