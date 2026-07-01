// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Concept - Use Disjoint Union Set, return number of Unique Parents
// Concept 2 - DFS

#include <vector>
#include <iostream>

using namespace std;

// DFS method
void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[i] = true;

    for (int j = 0; j < adj[i].size(); j++)
    {
        if (adj[i][j] == 1 && !vis[j])
        {
            dfs(j, adj, vis);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int numOfProvinces = 0;
    vector<bool> vis(isConnected.size(), false);

    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!vis[i])
        {
            dfs(i, isConnected, vis);
            numOfProvinces++;
        }
    }

    return numOfProvinces;
}

// Disjoint Set Union Method
class DisjointSetUnion
{
public:
    int n;
    vector<int> parent, rank;
    int numProvinces;

    DisjointSetUnion(int n)
    {
        this->n = n;
        numProvinces = n;

        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB)
            return; // if same parents, do nothing - if this condition is true, it means there is a cycle

        if (rank[parentA] == rank[parentB])
        {
            // make either rank higher
            parent[parentB] = parentA;
            rank[parentA]++;
            numProvinces--;
        }
        else if (rank[parentA] > rank[parentB])
        { // case 2
            parent[parentB] = parentA;
            numProvinces--;
        }
        else
        {
            parent[parentA] = parentB; // case 3
            numProvinces--;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // use the DSU here
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    unionByRank(i, j);
                }
            }
        }

        return numProvinces;
    }
};

int main()
{
    vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int n = isConnected.size();

    DisjointSetUnion dsu(n);
    cout << dsu.findCircleNum(isConnected) << endl;

    return 0;
}