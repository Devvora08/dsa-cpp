#include <iostream>
#include <vector>

using namespace std;

// sort in chunks, {5,1,3,7,2,0} - sort idx 0,1, then 0,1,2 ..... o,n

void insertion(vector<int> &nums) {
    for(int i = 0; i < nums.size()-1; i++) {
        for(int j = i+1; j > 0; j--) {
            if(nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
            }
        }
    }

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {13, 34, 20, 5, 1, 10, 9};

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    insertion(nums);
    cout << endl;

    return 0;
}
