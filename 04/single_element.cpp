#include <iostream>
#include <vector>

using namespace std;

int single_el(vector<int> &nums)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums.size() == 1)
            return nums[mid];

        // ✅ handle edges
        if (mid == 0)
        {
            if (nums[mid] != nums[mid + 1])
                return nums[mid];
        }
        if (mid == nums.size() - 1)
        {
            if (nums[mid] != nums[mid - 1])
                return nums[mid];
        }

        // normal case
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
                st = mid + 2;
            else
                end = mid - 1;
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // eve odd eve odd eve odd --ele-- odd eve odd eve
    int ele = single_el(nums);
    cout << ele << endl;

    return 0;
}