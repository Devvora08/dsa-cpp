#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

int trapWater(vector<int> &water) {
        int n = water.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        

        int maxR = water[n-1];
        for(int i = n-1; i >=0; i--) {
            maxR = max(maxR, water[i]);
            right[i] = maxR;
        }

        int maxL = water[0];
        for(int i = 0; i < n; i++) {
            maxL = max(maxL, water[i]);
            left[i] = maxL;
        }

        int waterHeight = 0;
        for(int i = 0; i < n; i++) {
            waterHeight+= min(left[i], right[i]) - water[i];
        }   

        return waterHeight;
}

int trap(vector<int>& height) {
    int ans = 0;
    int lmax = 0;
    int rmax = 0;
    int l = 0;
    int r = height.size() - 1;

    while(l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if(lmax < rmax) {
            // left is the deciding boundry
            ans += lmax - height[l];
            l++;
        } else {
            // right side is the deciding boundry
            ans += rmax - height[r];
            r--;
        }
    }

    return ans;
}

int main() {
    vector<int> water = {4,2,0,3,2,5};
    cout << trap(water) << endl;
    return 0;
}