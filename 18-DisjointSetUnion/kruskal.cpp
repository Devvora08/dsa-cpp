#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Kruskal Algorithm - Gives the weight of Minimum Spanning Tree using DSU (if parents == equal, cycle) + Sorting Edges by weight 
// and looping through edges for V-1 times 

class Edge{
    public:
        int u;
        int v;
        int wt;

        Edge(int u, int v, int wt) {
            this->u = u;
            this->v = v;
            this->wt = wt;
        }

        // create comparator that sorts on bases of weight when sorting is called
        bool operator<(const Edge &other) const {
            return this->wt < other.wt;
        }
};

class Graph{
    public:
        int V;
        vector<Edge> edges;
        vector<int> parent, rank;

        Graph(int V) {
            this->V = V;

            for(int i = 0; i < V; i++) {
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        void addEdge(int u, int v, int wt) {
            edges.push_back(Edge(u, v, wt));
        }

        int find(int x) {
            if(parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        } 

        void unionByRank(int a, int b) {
            // find the parents first
            int parentA = find(a);
            int parentB = find(b);

            if(parentA == parentB) {
                return; // Cycle is present
            } 

            if(rank[parentA] == rank[parentB]) {
                parent[parentB] = parentA;
                rank[parentA]++;
            } else if(rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else {
                parent[parentA] = parentB;
            }
        }

        void Kruskul_algo() {  // O(ElogE) + O(1)
            sort(edges.begin(), edges.end());
            int mstCost = 0;
            int count = 0;

            for(int i = 0; i < edges.size() && count < V; i++) {
                Edge e = edges[i];

                int parU = find(e.u);
                int parV = find(e.v);

                if(parU != parV) {  // no cycle
                    unionByRank(e.u, e.v);
                    mstCost += e.wt;
                    count++;
                }
            }

            cout << "MST Cost : " << mstCost << endl;
        }
};

int main() {
    Graph g(4);

    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);

    g.Kruskul_algo();

    return 0;
}