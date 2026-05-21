#include <vector>
#include <iostream>

using namespace std;

// choose a pivot in the array. after first pass, all elements < p will be on lhs of p
// and all elements > p will be rhs of p
// [5,4,3,2,1] - p = 4, then [1,3,2,4,5] - after first pass. keep doing that till sorted

int partition(vector<int> &nums, int st, int end) {
    int pivot = nums[end];
    int idx = st-1;
    
    for(int j = st; j < end; j++) {
        if(nums[j] <= pivot) {
            idx++;
            swap(nums[j], nums[idx]);
        }
    }

    idx++;
    swap(nums[end], nums[idx]);

    return idx;
}

void quickSort(vector<int> &nums, int st, int end) {
    if(st < end) {
        int pivIdx = partition(nums, st, end);
        
        quickSort(nums, st, pivIdx-1);
        quickSort(nums, pivIdx+1, end);
    }
}



int main() {
    vector<int> nums = {2,1,10,8,7,4,5};
    quickSort(nums, 0, nums.size()-1);

    for(int i : nums) {
        cout << i <<  " ";
    }
    cout << endl;

    return 0;
}