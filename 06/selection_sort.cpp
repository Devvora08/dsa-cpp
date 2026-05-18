#include <iostream>
#include <vector>

using namespace std;

void swap_num(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

int getMax(vector<int> &nums, int s, int e)
{
    int max = s;
    for (int i = s; i <= e; i++) 
    {
        if (nums[i] > nums[max])
        {
            max = i;
        }
    }

    return max;
}

void selection(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int end = nums.size() - i - 1;
        int max_el = getMax(nums, 0, end);
        swap_num(nums[end], nums[max_el]);
    }

    for (int i : nums)
    {
        cout << i << " ";
    }
}

// selection sort - pick the largest / smallest element each time and place it in correct idx
int main()
{
    vector<int> nums = {13, 34, 20, 5, 1, 10, 9};

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    selection(nums);
    cout << endl;
}