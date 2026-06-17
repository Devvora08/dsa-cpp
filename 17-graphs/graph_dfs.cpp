#include <vector>
#include <iostream>
#include <queue>
#include <list>

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
            l[v].push_back(u);
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
};

int main() {
    Graph g(5);
    vector<bool> vis(5, false);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    // g.display_list();
    g.dfs_traversal();

    return 0;
}