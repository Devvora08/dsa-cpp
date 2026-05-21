#include <vector>
#include <iostream>

using namespace std;

// count pairs of inversion - where pair -> nums[i] > nums[j] && i < j

int brute_count_inversions(vector<int> &nums) {
    // O(n^2) approach
    int count = 0;
    int n = nums.size()-1;
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[i] > nums[j]) count++;
        }
    }

    return count;
}

int merge(vector<int> &nums, int st, int mid, int end) {
    vector<int> temp;
    int inversionCount = 0;

    int i = st, j = mid+1;
    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            inversionCount += mid - i + 1;
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

    for(int idx = 0; idx < temp.size();  idx++) {
        nums[st+idx] = temp[idx];
    }

    return inversionCount;
}

int mergeSort(vector<int> &nums, int st, int end) {
    if(st < end) {
        int mid = st + (end - st)/2;

        // call for left and right
        int leftCount = mergeSort(nums, st, mid);
        int rightCount = mergeSort(nums, mid+1, end);

        int invCount = merge(nums, st, mid, end);

        return leftCount + rightCount + invCount;
    }

    return 0;
}

int main() {
    vector<int> nums = {6,3,5,2,7};

    //cout << brute_count_inversions(nums) << endl;

    cout << mergeSort(nums, 0, nums.size()-1) << endl;
     
    return 0;
}