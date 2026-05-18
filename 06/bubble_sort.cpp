#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &nums) {
    for(int i = 0; i < nums.size()-2; i++) {
        bool isSwapped = false;
        for(int j = 0; j < nums.size()-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                isSwapped = true;
            }
        }
        if(!isSwapped) return;
    }
}
 
int main() {
    vector<int> nums = {13,34,20,5,1,10,9};
    vector<int> num = {1,2,3,4,5,6,7,8};
    for(int i :  num) {
        cout << i << " ";
    } 
    cout << endl;

    bubbleSort(num);
    for(int i :  num) {
        cout << i << " ";
    } 
    cout << endl;

    return 0;
}