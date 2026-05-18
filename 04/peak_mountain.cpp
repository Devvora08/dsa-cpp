#include <iostream>
#include <vector> 

using namespace std;

int optimal_binary_search(vector<int> &arr,int st, int end, int target)
{
    bool asc = false;

    int idx = -1;

    if (arr[st] < arr[end])
    {
        asc = true;
    }

    if (asc)
    {
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] == target)
            {
                idx = mid;
                return idx;
            }
            else if (target <  arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    else
    {
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (target == arr[mid])
            {
                idx = mid;
                return idx;
            }
            else if (target > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }

    return idx;
    
}

int peak(vector<int> &arr) {
    int st = 0;
    int end = arr.size() - 1;

    while(st < end){
        int mid = st + (end - st) /2 ;
        if(arr[mid] < arr[mid+1]) {
            st = mid+1;
        } else {
            end = mid;
        }
    }

    return st; // or end, same val
}

int main() {
    vector<int> arr = {2,3,4,7,6,5,1,0};
    int target = 15;
    int peak_el = peak(arr);

    cout <<  peak_el << endl;
    int idx = optimal_binary_search(arr, 0, peak_el, target);
    if(idx == -1) {
        idx = optimal_binary_search(arr, peak_el+1, arr.size()-1, target);
    }

    cout << "idx : " << idx << endl;
    
    return 0;
}