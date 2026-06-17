// All graphs problems within single class
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

        void display_list() {
            for(int i = 0; i < V; i++) {
                cout << i << " : ";
                for(int neighbour : l[i]) {
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }

        bool isCycleUndirectedDfs(int src, vector<bool>&vis, int parent) {
            vis[src] = true;
            list<int> neighbors = l[src];

            for(int v : neighbors) {
                if(!vis[v]) {
                    if(isCycleUndirectedDfs(v, vis, src)) {
                        return true;
                    }
                } else if(v != parent) {
                    return true;
                }
            }

            return false;
        }

        bool isCycle() {
            vector<bool> vis(V, false);
            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(isCycleUndirectedDfs(i, vis, -1)) return true;
                }
            }

            return false;
        }
};


int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.display_list();

    cout << g.isCycle() << endl;

    return 0;
}