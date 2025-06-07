#include <iostream>
#include <vector>
#include "kruskal.h"
using namespace std;
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj[V];

    cout << "Enter the edges in the format (u, v, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
    }
    int mstCost = spanningTree(V, adj);
    cout << "The cost of the Minimum Spanning Tree is: " << mstCost << "\n\n";
    return 0;
}
// g++ main.cpp kruskal.cpp utils.cpp -o mst
// ./mst 
