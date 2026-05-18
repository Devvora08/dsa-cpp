#include <algorithm>
#include <vector> 
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    // sort the array
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int p1 = j+1, p2 = n-1;
            
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            while(p1 < p2) {
                int left = nums[i]+nums[j];
                int right = (nums[p1] + nums[p2]);

                long long sum = (long long)left+right;

                if(sum < target) {
                    p1++;
                } else if(sum > target) {
                    p2--;
                } else {
                    vector<int> four = {nums[i], nums[j], nums[p1], nums[p2]};
                    ans.push_back(four);

                    p1++, p2--;

                    while(p1 < p2 && nums[p1] == nums[p1-1]) p1++;
                    while(p1 < p2 && nums[p2] == nums[p2+1]) p2--;
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,-2,-1,0,3,2,1,4,-2,-3};
    
    vector<vector<int>> result = fourSum(nums, 3);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}