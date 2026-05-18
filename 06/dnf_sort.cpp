#include <iostream>
#include <vector>

using namespace std;

// dnf - dutch national flag algorithm, sorts - 0s,1s,2s (3 components basically)
// use 3 pointers, 4 partitions

// 0s - 0 to low-1
// 1s - low to mid-1
// 2s - high+1 to n-1

// mid - high range - unsorted elements

// 0 -> swap(nums[l], nums[m]), low++, mid++
// 1 -> mid++
// 2 -> swap(nums[h], nums[mid]), h--

void dnf(vector<int> &nums) {
    int mid = 0; 
    int high = nums.size()-1;
    
    int low = 0;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[high], nums[mid]);
            high--;
        }
    }

    for(int i : nums) {
        cout << i << " " ;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0,2,2,1,2,1,1,0,0,0,1};

    for(int i : nums) {
        cout << i << " " ;
    }
    cout << endl;

    dnf(nums);

    return 0;
}