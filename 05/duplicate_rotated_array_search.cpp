#include <vector>
#include <iostream>

using namespace std;

int binary_search(vector<int> &nums, int st, int end, int tar)
{
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid] == tar)
            return mid;
        else if (tar < nums[mid])
            end = mid - 1;
        else
            st = mid + 1;
    }

    return -1;
}

int pivot(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && nums[mid] > nums[mid + 1])
            return mid;
        if (mid > start && nums[mid] < nums[mid - 1])
            return mid - 1;

        // shrink start, end if duplicates
        if (nums[start] == nums[mid] && nums[mid] == nums[end])
        {
            if (start < end && nums[start] > nums[start + 1])
                return start;
            start++;

            if (end > start && nums[end] < nums[end - 1])
                return end - 1;
            end--;
        }

        // now shift start/end pointers accordingly taking note of
        // duplicates
        else if (nums[mid] > nums[start] ||
                 (nums[mid] == nums[start] && nums[mid] > nums[end]))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

bool search(vector<int> &nums, int target)
{
    int pivot_el = pivot(nums);

    if (pivot_el == -1)
        return binary_search(nums, 0, nums.size() - 1, target) != -1;

    if (target == nums[pivot_el])
        return true;

    if (target >= nums[0])
        return binary_search(nums, 0, pivot_el - 1, target) != -1;
    return binary_search(nums, pivot_el + 1, nums.size() - 1, target) != -1;
}

int main()
{
    vector<int> nums = {8, 9, 9, 9, 10, 1, 2, 3, 3, 7, 8};
    bool val = search(nums, 3);
    int pivot_el = pivot(nums);
    cout << pivot_el << endl;
    cout << val << endl;

    return 0;
}