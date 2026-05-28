#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

int lar_rec(vector<int> &histo) {
    int largest = INT16_MIN;
    for(int i = 0; i < histo.size(); i++) {

        int curr = histo[i];
        int minHeight = histo[i];
        largest = max(largest, curr);

        for(int j = i+1; j < histo.size(); j++) {
            minHeight = min(minHeight, histo[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            
            largest = max(largest, area);
        }
    }

    return largest;
}

int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> s;

        for(int i = n-1; i >=0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int height = heights[i];
            int currArea = height * width;
            ans = max(currArea, ans);
        }

        return ans;
}

int main() {
    vector<int> histo = {2,1,5,6,2,3};
    cout << largestRectangleArea(histo) << endl;

    return 0;
}