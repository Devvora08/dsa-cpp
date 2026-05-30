#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// Given a square matrix mat[][] of size n x n, where mat[i][j] == 1 means person i knows person j, and mat[i][j] == 0 means person i does not know person j, find the celebrity person where,

// A celebrity is defined as someone who:

// Is known by everyone else
// Does not know anyone (except themselves)
// Return the index of the celebrity if one exists, otherwise return -1.

int getCeleb(vector<vector<int>> arr) {
    int n = arr.size();
    stack<int> s;

    for(int i = 0; i < n; i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(arr[i][j] == 0) {
            s.push(i);
        } else {
            s.push(j);
        }
    }

    int celeb = s.top();
    for(int i = 0; i < n; i++) {
        if((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)) {
            return -1;
        }
    }

    return celeb;
}

int main() {
    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};
    cout << getCeleb(mat) << endl;

    return 0;
}