#include <vector>
#include <iostream> 

using namespace std;

bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expectedVal) {
    // base cases
    if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != expectedVal) return false;

    if(expectedVal == n*n-1) return true;

    return 
        isValid(grid, r-2, c+1, n, expectedVal+1) ||
        isValid(grid, r-1, c+2, n, expectedVal+1) ||
        isValid(grid, r+1, c+2, n, expectedVal+1) ||
        isValid(grid, r+2, c+1, n, expectedVal+1) ||
        isValid(grid, r+2, c-1, n, expectedVal+1) ||
        isValid(grid, r+1, c-2, n, expectedVal+1) ||
        isValid(grid, r-1, c-2, n, expectedVal+1) ||
        isValid(grid, r-2, c-1, n, expectedVal+1)
    ;

}

int main() {
    vector<vector<int>> grid = {{0,3,6}, {5,8,1}, {2,7,4}};

    cout << isValid(grid, 0,0, grid.size(), 0) << endl;

    return 0;
}