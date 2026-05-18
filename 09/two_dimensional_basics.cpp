#include <iostream>
#include <vector> 

using namespace std;

void print_2d() {
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};

    // cout << arr[2][1] << endl;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++){
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }

    cout << endl;
}

void linear_search(vector<vector<int>>& arr, int tar) {
    int r = arr.size();
    int c = arr[0].size();

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == tar) {
                cout << "Index : " << i << " " << j << " ";
                cout << endl;
            }
        }
    }
}

void printColSum(vector<vector<int>>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = 0; j < arr[0].size(); j++) {
            sum += arr[j][i];
        }
        cout << "Sum of " << i << "th column : " << sum << endl;
    }
}

int printDiagnol(vector<vector<int>>& arr) {
    // primary diagnol (left to right)
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr[0].size(); j++) {
            if(i == j) {
                sum += arr[i][j];
            }
        }
    }
    

    // secondary diagnol (right to left)
    // row++, col--
    int second_sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            if(j == arr.size()-i-1) {
                second_sum += arr[i][j];
            }
        }
    }


    int mid = arr.size()/2;

    return sum + second_sum - arr[mid][mid];
}

int main() {
    //print_2d();

    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    // linear_search(arr, 2);

    //printColSum(arr);
    cout << printDiagnol(arr) << endl;

    return 0;
}