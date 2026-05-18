#include <iostream>
#include <vector>

using namespace std;

int binary_search(int st, int end, vector<int>& nums, int target) {
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target) return mid;
        else if (target < nums[mid]) end = mid - 1;
        else st = mid + 1;
    }
    return -1;
}

int find_peak(vector<int> nums)
{
    // this function searches the peak element in the array
   
    // 6,7,8,1,2,3,4,5  ---> 6-8 , 1-5
    int st = 0;
    int end = nums.size() - 1;
    while (st < end)

    {
        int mid = st + (end - st) / 2;
        if (nums[mid] > nums[end]) {
            st = mid + 1;
        } else {
            end = mid;
        }
    }

    return st;
}

int main()
{
    vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};
    int peak_el = find_peak(arr);
    int target = 8;
    int idx;

    // now do 2 binary searches from 0 - peak, peak + 1 - end
   if (target >= arr[peak_el] && target <= arr.back()) {
    idx = binary_search(peak_el, arr.size()-1, arr, target);
} else {
    idx = binary_search(0, peak_el-1, arr, target);
}

    cout << "this is the peak element idx : " << peak_el << endl;
    cout << "idx of the target is : " << idx << endl;

    return 0;
}