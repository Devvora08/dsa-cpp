#include <iostream> 
#include <vector>

using namespace std;

int main() {
    // array needs to be sorted
    vector<int> nums = {1,2,3,4,5,6,7,8,89,200};
    int target = 7;

    int st = 0;
    int end = nums.size()-1;

    while(st <= end) {
        int mid = (st+end)/2;

        if(nums[mid] == target) {
            cout << mid << endl;
            break;
        }  else if(target < nums[mid]){
            end = mid-1;
        } else {
            st = mid+1;
        }
    }

    return 0;
}