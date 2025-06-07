#ifndef UTILS_H
#define UTILS_H

void logFindParent(int u);
void logFindParentRecursive(int u);
void logParent(int u, bool isParent);
void logUnionByRank(int u, int v);
void logUnionAttach(int parent, int child);
void logUnionEqualRank(int parent, int child);
void logStartingKruskal();
void logAddingEdge(int u, int v, int weight);
void logProcessingEdge(int u, int v, int weight);
void logIncludingEdge(int u, int v, int weight);
void logSkippingEdge(int u, int v);
void logMSTCost(int cost);

#endif
