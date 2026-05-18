#include <vector> 
#include <iostream>

using namespace std;

void print_subsets(vector<int> &nums, vector<int> &subsets, int i) {
    // approach -print with element include, backtrack,print with element exclude

    if(i == nums.size()) {
        for(int n : subsets) {
            cout << n << " ";
        }
        cout << endl;
        return;
    };

    // include
    subsets.push_back(nums[i]);
    print_subsets(nums, subsets, i+1);

    // backtrack, exclude
    subsets.pop_back();
    // add a while loop to skip to non repeating element
    int idx = i+1;
    while(idx < nums.size() && nums[idx] == nums[idx-1]) {
        idx++;
    }

    print_subsets(nums,subsets, idx);
}

int main() {
    vector<int> nums = {1,2,2};
    vector<int> subsets;

    print_subsets(nums, subsets, 0);

    return 0;
}