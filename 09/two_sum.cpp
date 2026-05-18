#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>

using namespace std;

vector<int> twosum(vector<int> &arr, int sum) {
    // brute force, check all the pairs
    vector<int> ans = {};
    for(int i = 0; i < arr.size()-1; i++) {
        int targetSum = 0;
        for(int j = i+1; j < arr.size(); j++) {
            targetSum = arr[i] + arr[j];
            if(targetSum == sum) {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                break;
            }
        }
    }

    return ans;
}

vector<int> sort_two_sum(vector<int> &arr, int sum) {
    // sort the array, use 2 sum
    // O(nlogn)
    sort(arr.begin(), arr.end());
    // for(int i : arr) {
    //     cout << i << " ";
    // }
    // cout << endl;
    vector<int> ans = {};

    int i = 0, j = arr.size()-1;
    while(i < j) {
        if(arr[i] + arr[j] == sum) {
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            return ans;
        } else if(arr[i] + arr[j] < sum) i++;
        else j--;
    }

    return ans;
}

vector<int> optimal_twosum(vector<int> &nums, int target) {
    // returns actual values, not indices. for index, use map
    vector<int> ans;
    set<int> c;
    for(int i = 0; i < nums.size(); i++) {
        if(c.find(target - nums[i]) == c.end()) {
            c.insert(nums[i]);
        } else {
            ans.push_back(target - nums[i]);
            ans.push_back(nums[i]);
            return ans;
        }
    }

    return ans;
}

int main() {
    vector<int> arr =  {2,4,6,1,10,9};
    int sum = 8;

    vector<int> sol = optimal_twosum(arr, sum);
    cout << sol[0] << " " << sol[1] << endl;

    return 0;
}