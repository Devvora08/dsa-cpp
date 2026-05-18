#include <iostream>
#include <vector>

using namespace std;

void rotate_by_k_to_left(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    vector<int> k_ele_arr;
    for (int i = 0; i < k; i++)
    {
        k_ele_arr.push_back(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        nums[i - k] = nums[i];
    }
    int idx_k = 0;
    for (int i = n - k; i < n; i++)
    {
        nums[i] = k_ele_arr[idx_k];
        idx_k++;
    }

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

void rotate_by_k_to_right(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    vector<int> k_ele_arr;
    for (int i = n - k; i < n; i++)
    {
        k_ele_arr.push_back(nums[i]);
    }

    for (int i = n - k - 1; i >= 0; i--)
    {
        nums[i + k] = nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = k_ele_arr[i];
    }

    for (int i : nums)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> nums = {3, 8, 10, 1, 5, 0, 11};
    int k = 10;

    rotate_by_k_to_right(nums, k);
    return 0;
}