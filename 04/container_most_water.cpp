#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Ex:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49

// non optimal solution - get area of all possible combinations, record the max (O<n^2>)
int area(vector<int> nums) {
    int max_area_water = INT32_MIN;
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            int current_area = (j-i) * min(nums[j], nums[i]);
            max_area_water = max(max_area_water, current_area);
        }
    }

    return max_area_water;
}

// optimal - 2 pointer solution - O<n> time complexity
int optimal_max_area(vector<int> height) {
    int max_area_water = INT32_MIN;

    int n = height.size();
    int i = 0;
    int j = n-1;

    // while loop till pointer i, j meet
    while(i != j) {
        int current_area = (j-i) * min(height[i], height[j]);
        max_area_water = max(max_area_water, current_area);

        if(height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }

    return max_area_water;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = area(height);
    int optimal = optimal_max_area(height);

    cout<< ans << endl;
    cout << optimal << endl;
    return 0;
}