// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]

class Solution {
public:
    bool isCycleDfs(int src, vector<bool>& vis, vector<bool>& recPath,
                    vector<vector<int>>& prerequisites) {

        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if (u == src) {
                if (!vis[v]) {
                    if (isCycleDfs(v, vis, recPath, prerequisites))
                        return true;
                }
                else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topological_helper(int curr,
                            vector<bool>& vis,
                            stack<int>& s,
                            vector<vector<int>>& prerequisites) {

        vis[curr] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if (u == curr) {
                if (!vis[v]) {
                    topological_helper(v, vis, s, prerequisites);
                }
            }
        }

        s.push(curr);
    }

    void topologicalSort(int numCourses,
                         vector<vector<int>>& prerequisites,
                         stack<int>& s) {

        vector<bool> vis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topological_helper(i, vis, s, prerequisites);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        vector<int> ans;

        // Step 1: Detect Cycle
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycleDfs(i, vis, recPath, prerequisites)) {
                    return {};
                }
            }
        }

        // Step 2: Topological Sort
        stack<int> s;
        topologicalSort(numCourses, prerequisites, s);

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};