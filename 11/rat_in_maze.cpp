#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<vector<int>> &matrix, int r, int c, string path, vector<string>& ans) {
    int n = matrix.size();
    if(r < 0 || r >= n || c < 0 || c >= n || matrix[r][c] == 0 || matrix[r][c] == -1) return;

    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    matrix[r][c] = -1;

    helper(matrix, r+1, c, path+"D", ans);
    // helper(matrix, r-1, c, path+"U", ans);
    // helper(matrix, r, c-1, path+"L", ans);
    helper(matrix, r, c+1, path+"R", ans);

    matrix[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> matrix) {
    vector<string> ans; 
    string path = "";

    helper(matrix, 0,0,path, ans);

    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};

    vector<string> ans = findPath(matrix);
    for(string path: ans) cout << path << endl;
    
    return 0;
}