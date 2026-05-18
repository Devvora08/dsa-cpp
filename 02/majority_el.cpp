#include <iostream>
#include <vector>
using namespace std;


int brute_force(int bf[], int n) {
    for(int i = 0; i < n; i++) {
        int freq = 0;
        for(int el = 0; el < n; el ++) {
            if(bf[el] == bf[i]) {
                freq++;
            }
        }
        if(freq > n/2) {
            return bf[i];
        }
    }
    return -1;
}

int moore_alg(vector<int> nums, int n) {
    int maj;
    int freq = 0;
    for(int i = 0; i < n; i++) {
        if(freq == 0) {
            maj = nums[i];
        }
        if(maj == nums[i]) {
            freq ++;
        } 
        else {
            freq--;
        }
    }

    return maj;
}


int main() {
    int arr[] = {1,2,2,3,2};
    //int len = sizeof(arr); - use this to get length of array. 

    vector<int> vect = {1,2,2,3,2,3,5,6,7,4,3,4,5,2,2,3,4,4,4,5,5,4,4,3,3,3,3,3,3,5,6};
    int size = vect.size();

    int n = 5;

    int maj = brute_force(arr, n);
    //cout << maj << endl;

    int moore_maj = moore_alg(vect, size);
    cout << moore_maj << endl;

    return 0;
}