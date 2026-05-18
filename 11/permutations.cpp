#include <iostream>
#include <vector>

using namespace std;

// print all permutations / store all permutations of a vector integer array
// example - 123 - 132, 213,232, 312,321, 123

void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getPerms(nums,idx+1, ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>&nums) {
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);

    return ans;
}

void printPerm(string pro, string unpro) {
    if(unpro.size() == 0) {
        cout << pro << endl;
        return;
    }

    char ch = unpro.at(0);
    for(int i = 0; i <= pro.size(); i++) {
        string first = pro.substr(0,i);
        string second = pro.substr(i, pro.size());
        
        printPerm(first + ch + second, unpro.substr(1));
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>>ans = permute(nums);

    // for(int i = 0; i < ans.size(); i++) {
    //     for(int j = 0; j < ans[i].size(); j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    printPerm("", "abcdef");

    return 0;
}