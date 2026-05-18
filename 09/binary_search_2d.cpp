#include <iostream>
#include <vector> 

using namespace std;

// O(log [m*n])
bool generalised_binary_search(vector<vector<int>>& nums, int tar) {
    int rows = 0;
    int cols = nums[0].size()-1;

    while(rows < nums.size() && cols >= 0) {
        if(tar == nums[rows][cols]) {
            return true;
        } else if(tar < nums[rows][cols]) {
            cols--;
        } else {
            rows++;
        }
    } 

    return false;
}

int main() {
    vector<vector<int>> nums = {{1,4,7,8}, {10,13,17,20}, {25,31,36,44}};

    cout << generalised_binary_search(nums, 45) << endl;

    return 0;
}