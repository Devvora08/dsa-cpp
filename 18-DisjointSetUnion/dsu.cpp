#include <vector>
#include <iostream>

using namespace std;

// Two sets are called disjoint sets if they don't have any element in common. The disjoint set data structure is used to store such sets. It supports following operations:

// Merging two disjoint sets to a single set using Union operation.
// Finding representative of a disjoint set using Find operation.
// Check if two elements belong to same set or not. We mainly find representative of both and check if same.
// Consider a situation with a number of persons and the following tasks to be performed on them:

// Add a new friendship relation, i.e. a person x becomes the friend of another person y i.e adding new element to a set.
// Find whether individual x is a friend of individual y (direct or indirect friend)

// Example:
// We are given 10 individuals say, a, b, c, d, e, f, g, h, i, j

// Following are relationships to be added:
// a <-> b  
// b <-> d
// c <-> f
// c <-> i
// j <-> e
// g <-> j

// Given queries like whether a is a friend of d or not. We basically need to create following 4 groups and maintain a quickly accessible connection among group items:
// G1 = {a, b, d}
// G2 = {c, f, i}
// G3 = {e, g, j}
// G4 = {h}

class DisjointSetUnion {
    public:
        int n;
        vector<int> parent, rank;

        DisjointSetUnion(int n) {
            this->n = n;

            for(int i = 0; i < n; i++) {
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        void unionByRank(int a, int b) {
            int parentA = find(a);
            int parentB = find(b);

            if(parentA == parentB) return; // if same parents, do nothing - if this condition is true, it means there is a cycle

            if(rank[parentA] == rank[parentB]) {
                // make either rank higher
                parent[parentB] = parentA;
                rank[parentA]++;
            } else if(rank[parentA] > rank[parentB]) {  // case 2
                parent[parentB] = parentA;
            } else {
                parent[parentA] = parentB;   // case 3
            }
        }

        int find(int x) {
            if(parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void getInfo() {
            for(int i=0; i < n; i++) {
                cout << parent[i] << " ";
            } 
            cout << endl;

            for(int i=0; i < n; i++) {
                cout << rank[i] << " ";
            } 
            cout << endl;
        }
};

int main() {
    DisjointSetUnion dsu(6);

    dsu.getInfo();

    dsu.unionByRank(0,2);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}