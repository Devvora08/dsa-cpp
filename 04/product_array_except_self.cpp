#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// non optimized, uses O<n> + O(n^2) time + extra space
void product_arr_exce_self(vector<int> &nums)
{
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int prod = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j) {
                continue;
            }
    
            prod = prod * nums[j];
        }
        result[i] = prod;
    }
    for (int i : result)
    {
        cout << i << endl;
    }
}

// optimized version - only O<n> space
void optimized_product_array_except_self(vector<int> nums) {
    // prefix suffix
    int n = nums.size(); 
    int suffix = 1;
    vector<int> ans(n, 1);

    // prefix -> [1,2,3,4] 
    //       =   [1,1,2,6]
    for(int i = 1; i < ans.size(); i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }    

    // suffix -> [1,2,3,4]
    //        =  [24,12,4,1]
    for(int i = n-2; i >= 0; i--) {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    // display result
    for(int i : ans) {
        cout << i << endl;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    for (int i : nums)
    {
        cout << i << endl;
    }
    cout << endl;

    // product_arr_exce_self(nums);
    optimized_product_array_except_self(nums);

    return 0;
}