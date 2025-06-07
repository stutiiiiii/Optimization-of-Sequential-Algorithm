#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>

int findParent(int u, std::vector<int>& parent);
void unionByRank(int u, int v, std::vector<int>& parent, std::vector<int>& rank);
int spanningTree(int V, std::vector<std::vector<int>> adj[]);

#endif
