#include <iostream>
#include <vector>
#include <queue>
#include "kruskal.h"
#include "utils.h"
using namespace std;

int findParent(int u, vector<int>& parent) {
    logFindParent(u);
    if (u == parent[u]) {
        logParent(u, true);
        return u;
    } else {
        logFindParentRecursive(u);
        return parent[u] = findParent(parent[u], parent);  // Path compression
    }
}

void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    logUnionByRank(u, v);
    int ultimateParentU = findParent(u, parent);
    int ultimateParentV = findParent(v, parent);

    if (rank[ultimateParentU] > rank[ultimateParentV]) {
        logUnionAttach(ultimateParentU, ultimateParentV);
        parent[ultimateParentV] = ultimateParentU;
    } else if (rank[ultimateParentU] < rank[ultimateParentV]) {
        logUnionAttach(ultimateParentV, ultimateParentU);
        parent[ultimateParentU] = ultimateParentV;
    } else {
        logUnionEqualRank(ultimateParentU, ultimateParentV);
        parent[ultimateParentV] = ultimateParentU;
        rank[ultimateParentU]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[]) {
    logStartingKruskal();
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < V; i++) {
        int n = adj[i].size();
        for (int j = 0; j < n; j++) {
            int neighbor = adj[i][j][0];
            int weight = adj[i][j][1];
            logAddingEdge(i, neighbor, weight);
            pq.push({weight, {i, neighbor}});
        }
    }

    int cost = 0;
    int edges = 0;
    vector<string> treeDirection(V, "");  // To store the tree direction for each node

    while (!pq.empty() && edges < V - 1) {
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        logProcessingEdge(u, v, weight);

        if (findParent(u, parent) != findParent(v, parent)) {
            logIncludingEdge(u, v, weight);
            cost += weight;
            edges++;

            // Union operation
            unionByRank(u, v, parent, rank);

            // Record the direction of the tree (attachments)
            if (treeDirection[u].empty()) {
                treeDirection[u] = to_string(u) + "->" + to_string(v);
            } else {
                treeDirection[u] += " " + to_string(u) + "->" + to_string(v);
            }

            if (treeDirection[v].empty()) {
                treeDirection[v] = to_string(v) + "->" + to_string(u);
            } else {
                treeDirection[v] += " " + to_string(v) + "->" + to_string(u);
            }
        } else {
            logSkippingEdge(u, v);
        }
    }

    // Log MST cost and tree directions after the while loop ends
    logMSTCost(cost);
    for (const string& direction : treeDirection) {
        if (!direction.empty()) {
            cout << direction << "\n";
        }
    }

    return cost;
}
