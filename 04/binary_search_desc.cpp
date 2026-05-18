#include <iostream>
#include <vector>

using namespace std;

int desc_binary_search(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

// optimal checks asc/desc and handles both cases
int optimal_binary_search(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;
    bool asc = false;

    int idx = -1;

    if (nums[st] < nums[end])
    {
        asc = true;
    }

    if (asc)
    {
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target)
            {
                idx = mid;
                return idx;
            }
            else if (target <  nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    else
    {
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (target == nums[mid])
            {
                idx = mid;
                return idx;
            }
            else if (target > nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }

    return idx;
    
}

int main()
{
    vector<int> nums = {1,2,4,6,8};
    int tar = 2;

    // practice binary search in desc order too
    //int idx = desc_binary_search(nums, tar);
    int idx = optimal_binary_search(nums, tar);
    cout << idx << endl;

    return 0;
}