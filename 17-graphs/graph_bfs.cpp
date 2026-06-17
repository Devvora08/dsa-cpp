#include <iostream>
#include <vector>
#include <list>
#include <queue>

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

        void bfs_traversal() {
            // can start from any vertex, but for simplicity traverse from 0
            queue<int> q;
            vector<bool> vis(V, false);

            q.push(0);
            vis[0] = true;

            while(q.size() > 0) {
                int u = q.front();
                q.pop();

                cout << u << " ";

                for(int v : l[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            cout << endl;
        }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    // g.display_list();
    g.bfs_traversal();

    return 0;
}