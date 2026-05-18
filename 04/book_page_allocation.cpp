#include <iostream>
#include <vector>

using namespace std;

// Given an array of integers A of size N and an integer B.
// College library has N bags,the ith book has A[i] number of pages.
// You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum

// Input 1:
//     A = [12, 34, 67, 90]
//     B = 2
// Output 1:
//     113
// Explanation 1:
//     There are 2 number of students. Books can be distributed in following fashion : 
//         1) [12] and [34, 67, 90]
//         Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
//         2) [12, 34] and [67, 90]
//         Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
//         3) [12, 34, 67] and [90]
//         Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

//         Of the 3 cases, Option 3 has the minimum pages = 113.

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxAllowedPages) return false;

        if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students ++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if(m > n) {
        return -1;
    }

    int sum = 0;
    for(int i : arr) {
        sum += i;
    }
    int ans = -1;
    int st = 0, end = sum; // range of possible answers

    while(st <= end) {
        int mid = st + (end-st) /2 ;
        
        if(isValid(arr, n, m, mid)) {  // true, then go left
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }   
    }

    return ans;
}

int main() {
    vector<int> books = {15,17,20};
    int n = books.size();
    int m = 2;

    int minMaxPages = allocateBooks(books, n,m);
    cout << minMaxPages << endl;

    return 0;
}
