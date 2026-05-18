#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // in place solution
    int idx = m+n -1;
    int i = m-1, j = n-1;

    while(i >= 0 && j>= 0) {
        if(nums1[i] >= nums2[j]) {
            nums1[idx--] = nums1[i--];
        } else {
            nums1[idx--] = nums2[j--];
        }
    }

    while(j >= 0) {
        nums1[idx--] = nums2[j--];
    }

    for(int i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 3, nums2, nums2.size());

    return 0;
}