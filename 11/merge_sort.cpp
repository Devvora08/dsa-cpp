#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&nums, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid+1;

    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int idx = 0; idx < temp.size(); idx++) {
        nums[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int> &nums, int st, int end) {
    if(st < end) {
        int mid = st + (end-st)/2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, st, mid, end);
    }
}

int main() {
    vector<int> nums = {3,5,1,10,6,2,12,18,0};

    mergeSort(nums,0, nums.size()-1);

    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}