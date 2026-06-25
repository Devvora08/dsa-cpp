#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<int> [V];
        }

        void addEdge(int u, int v) {
            l[u].push_back(v);
            // l[v].push_back(u);  for directed graph, only 1 connection from u --> v
        }

        // void display_list() {
        //     for(int i = 0; i < V; i++) {
        //         cout << i << " : ";
        //         for(int neighbour : l[i]) {
        //             cout << neighbour << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        void dfs_traversal_helper(int u, vector<bool> &vis) {
            // preorder manner
            cout << u << " ";
            vis[u] = true;

            for(int v : l[u]) {
                if(!vis[v]) {
                    dfs_traversal_helper(v, vis);
                }
            }
        }

        void dfs_traversal() {
            int src = 0;
            vector<bool> vis(V, false);

            dfs_traversal_helper(src, vis);
        }

        // cycle detection in directed graph
        bool isCycleDirected(int curr, vector<bool> &vis, vector<bool> & recursionPath) {
            vis[curr] = true;
            recursionPath[curr] = true;

            for(int neighbor : l[curr]) {
                if(!vis[neighbor]) {
                    if(isCycleDirected(neighbor, vis, recursionPath))
                        return true;
                }
                else if(recursionPath[neighbor]) {
                    return true;
                }
            }

            recursionPath[curr] = false;
            return false;
        }

        // main function, which takes care of all sets of possible cycles
        bool isCycle() {
            vector<bool> vis(V, false);
            vector<bool> recursionPath(V, false);

            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(isCycleDirected(i, vis, recursionPath)) {
                        return true;
                    }
                }
            }

            return false;
        }

        // Topological Sort - print in order of u ---> v where u prints before v for all nodes
        void topological_helper(int curr, vector<bool> &vis, stack<int>& s) {
            vis[curr] = true;

            for(int v : l[curr]) {
                if(!vis[v]) {
                    topological_helper(v, vis, s);
                }
            }

            s.push(curr);
        }

        void topologicalSort() {
            stack<int> s;
            vector<bool> vis(V, false);
            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    topological_helper(i, vis, s); 
                }
            }

            while(s.size() > 0) {
                cout << s.top() << " ";
                s.pop();
            }
        }
};

int main() {
    Graph g(5);
    vector<bool> vis(5, false);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,1);

    // g.display_list();
    g.dfs_traversal();
    cout << endl;

    //cout << g.isCycle() << endl;

    g.topologicalSort();

    return 0;
}