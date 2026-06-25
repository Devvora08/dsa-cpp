#include <vector> 
#include <iostream>
#include <queue>
#include <list>

using namespace std;

void numIslands(int i, int j,vector<vector<bool>>&vis, vector<vector<int>> &matrix, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || matrix[i][j] != 1) return;

    vis[i][j] = true;
 
    // visit the neighbours for all 4 sides
    numIslands(i-1, j, vis, matrix, n,m);
    numIslands(i, j+1, vis, matrix, n,m);
    numIslands(i+1, j, vis, matrix, n,m);
    numIslands(i, j-1, vis, matrix, n,m);
}

int main() {
    vector<vector<int>> matrix = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
    int islands = 0;
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 1 && !vis[i][j]) {
                numIslands(i,j,vis,matrix, n,m);
                islands++;
            }
        }
    }

    cout << islands << endl;

    return 0;
}