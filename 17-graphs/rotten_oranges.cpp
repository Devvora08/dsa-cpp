#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int rottenOranges(vector<vector<int>> &oranges) {
    int n = oranges.size();
    int m = oranges[0].size();

    int ans = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;

    // push all sources in queue with val == 2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(oranges[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }

    // bfs
    while(q.size() > 0) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();

        ans = max(ans, time);

        // check for top neighbor
        if(i-1 >= 0 && !vis[i-1][j] && oranges[i-1][j] == 1) {
            q.push({{i-1, j}, time+1});
            vis[i-1][j] = true;
        } 

        // check for right
        if(j+1 < m && !vis[i][j+1] && oranges[i][j+1] == 1) {
            q.push({{i, j+1}, time+1});
            vis[i][j+1] = true;
        } 

        // check for bottom
        if(i+1 < n && !vis[i+1][j] && oranges[i+1][j] == 1) {
            q.push({{i+1, j}, time+1});
            vis[i+1][j] = true;
        } 

        // check for left
        if(j-1 >= 0 && !vis[i][j-1] && oranges[i][j-1] == 1) {
            q.push({{i, j-1}, time+1});
            vis[i][j-1] = true;
        } 
    }

    // check for fresh orange
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(oranges[i][j] == 1 && !vis[i][j]) {
                return -1;
            }
        }
    }

    // return ans if no fresh oranges
    return ans;
}

int main() {
    vector<vector<int>> oranges{{2,1,1}, {1,1,0}, {0,2,1}};
   
    cout << rottenOranges(oranges) << endl;

    return 0;
}