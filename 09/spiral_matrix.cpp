#include <iostream>
#include <vector>

using namespace std;

void print_spiral(vector<vector<int>>& nums) {
    // initialize 4 ends, and run 4 loops
    int r = nums.size(), c = nums[0].size();
    int top = 0, left = 0, right = c-1, bottom = r-1;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            cout << nums[top][i] << " ";
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            cout << nums[i][right] << " ";
        }
        right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << nums[bottom][i] << " ";
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--){
                cout << nums[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}

int main() {
    vector<vector<int>> nums = {{1,4,7,8}, {10,13,17,20}, {25,31,36,44}, {2,34, 90, 76}};

    print_spiral(nums);

    return 0;
}