#include <iostream>
#include <vector> 

using namespace std;

// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
// Note: The second largest element should not be equal to the largest element.
// Examples:

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34

int sort_arr(vector<int> &nums) {
    // O(N^2) approach
    for(int i = 0; i < nums.size()-2; i++) {
        bool isSwapped = false;
        for(int j = 0; j < nums.size()-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                isSwapped = true;
            }
        }
    }
    int second_lar = 0;
    int counter = 0;
    for(int i = nums.size(); i >= 0; i--){
        if(counter == 2) {
            second_lar = nums[i];
        }
        counter++;
    }

    return second_lar;
}

int find_second_largest(vector<int> &nums) {
    // dynamic approach, O(N) time complexity
    int largest = INT16_MIN;
    int second_lar = INT16_MIN;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > second_lar && nums[i] < largest) {
            second_lar = nums[i];
        }
        if(nums[i] > largest) {
            second_lar = largest;
            largest = nums[i];
        }   
    }

    return second_lar;
}

// variation of 2nd largest - find 3rd largest
int find_third_largest(vector<int> &nums) {
    // same approach as for second largest, use 3 pointers
    int largest = INT16_MIN;
    int second_lar = INT16_MIN;
    int third_lar = INT16_MIN;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > third_lar && nums[i] < second_lar) {
            third_lar = nums[i];
        } else if(nums[i] > second_lar && nums[i] < largest) {
            third_lar = second_lar; 
            second_lar = nums[i];
        } else if(nums[i] > largest) {
            third_lar = second_lar;
            second_lar = largest; 
            largest = nums[i];
        }
    }

    return third_lar;
}

int main() {
    vector<int> nums = {12, 35, 1,60,45,11,98,100,14,99, 10, 34, 1};
    cout << find_third_largest(nums) << endl;
    return 0;
}