#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            cout << "Union(" << u << ", " << v << ") successful." << endl;
        } else {
            cout << "Elements " << u << " and " << v << " are already in the same set." << endl;
        }
    }
};

int main() {
    int n = 7; 
    DisjointSet dsu(n);

    dsu.unionSets(1, 2);
    dsu.unionSets(2, 3);
    dsu.unionSets(4, 5);
    dsu.unionSets(6, 7);
    dsu.unionSets(5, 6);

    if (dsu.find(3) == dsu.find(7)) {
        cout << "3 and 7 are connected." << endl;
    } else {
        cout << "3 and 7 are NOT connected." << endl;
    }

    dsu.unionSets(3, 7);

    if (dsu.find(3) == dsu.find(7)) {
        cout << "3 and 7 are connected now." << endl;
    } else {
        cout << "3 and 7 are NOT connected." << endl;
    }

    return 0;
}

