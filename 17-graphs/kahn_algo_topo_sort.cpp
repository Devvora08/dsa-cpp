// Topological sort using Kahn's algorithm - BFS
#include <iostream>
#include <vector>
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
            // l[v].push_back(u);  for directed graph, only 1 connection from u --> v
        }  
        
        void kahnTopoSort() {
            vector<int> result;

            // calculate indegree
            vector<int> indegree(V, 0);
            for(int u = 0; u < V; u++) {
                for(int v : l[u]) {
                    indegree[v]++;
                }
            } 

            // add 0 indegree in queue
            queue<int> q;
            for(int i = 0; i < V; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }

            // BFS
            while(q.size() > 0) {
                int curr = q.front();
                q.pop();
                result.push_back(curr);

                for(int v : l[curr]) {
                    indegree[v]--;
                    if(indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            // print result
            for(int val : result) {
                cout << val << " ";
            }
            cout << endl;
        }
};

int main() {
    Graph g(6);

    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.kahnTopoSort();

    return 0;
}