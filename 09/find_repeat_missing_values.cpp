#include <iostream>
#include <vector> 
#include <set>

using namespace std;

// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
    int n = nums.size();
    // n*n type grid
    int totalSum = 0;
    int repeating = -1;
    
    vector<int> ans;

    set<int> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s.find(nums[i][j]) != s.end()) {
                repeating = nums[i][j];
                ans.push_back(repeating);
            };

            s.insert(nums[i][j]);
            totalSum += nums[i][j];
        }
    }

    int expectedSum = (n*n) * (n*n +1)/2;
    ans.push_back(expectedSum - totalSum + repeating);

    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,3}, {2,2}};
    vector<int> ans = findMissingAndRepeatedValues(grid);

    for(int i : ans) {
        cout << i << endl;
    }

    return 0;
}