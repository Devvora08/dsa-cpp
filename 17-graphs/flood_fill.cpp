// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// Example 1:
// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& image, int i, int j, int color, int orgColor) {
    // base condition - boundaries + color check
    if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != orgColor || image[i][j] == color) {
        return;
    }

    image[i][j] = color;

    // 4 calls
    dfs(image, i-1, j, color, orgColor);
    dfs(image, i+1, j, color, orgColor);
    dfs(image, i, j-1, color, orgColor);
    dfs(image, i, j+1, color, orgColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // approach - 4 calls for top, left, right, bottom + base condition

   dfs(image, sr, sc, color, image[sr][sc]);

   return image;

}

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    for(int i = 0; i < image.size(); i++) {
        for(int j = 0; j < image[i].size(); j++) {
            cout << image[i][j] << " "; 
        }
        cout << endl;
    }

    cout << endl;
    
    vector<vector<int>> ans;

    ans = floodFill(image, sr,sc, color);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
}