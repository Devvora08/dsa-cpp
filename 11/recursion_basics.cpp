#include <iostream>
#include <vector>

using namespace std;

int sum_of_all_numbers_till_n(int n) {
    // return the sum of all numbers till n
    if(n == 0) return 0;

    return n + sum_of_all_numbers_till_n(n-1);
}

bool check_array_sorted(vector<int> &nums, int n) {
    // ascending array check
    if(n <= 1) return true;

    return nums[n-1] > nums[n-2] && check_array_sorted(nums, n-1);
}

int fibonacci_num(int n) {
    // return the nth fibonacci number
    if(n <= 1) return 1;

    return fibonacci_num(n-1) + fibonacci_num(n-2);
}

int n_factorial(int n) {
    // return the factorial of n

    if(n <= 1) return 1;

    return n * n_factorial(n-1);
}

bool binary_search(vector<int> &nums,int target, int st, int end) {
    if(st > end) return false;
    
    int mid = st + (end-st)/2;
    if(nums[mid] == target) return true;

    if(target < nums[mid]) {
        return binary_search(nums,target, st, mid-1);
    }  
    return binary_search(nums,target, mid+1, end);
}

void towerOfHanoi(int n, char from, char to, char usingrod) {
    if (n == 0) return;

    towerOfHanoi(n-1, from, usingrod, to);
    cout << "Shift disk -> "<< n << " from " << from << " to " << to << endl;
    towerOfHanoi(n-1, usingrod, to, from);
}

int main() {
    // covers basic recusrive problems
    vector<int> nums = {1,2,10,20,25,30,43};
    //cout << check_array_sorted(nums, 6) << endl;
    //cout << sum_of_all_numbers_till_n(6) << endl;

    //cout << fibonacci_num(10) << endl;

    //cout << n_factorial(5) << endl;

    //cout << binary_search(nums,25, 0, nums.size()-1) << endl;

    towerOfHanoi(3, 'A','C','B');

    return 0;
}