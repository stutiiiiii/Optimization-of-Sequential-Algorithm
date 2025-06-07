#include <iostream>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds

// Function to create a 500ms gap
void addDelay() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void logFindParent(int u) {
    std::cout << "findParent: Checking the parent of node " << u << "\n" << std::endl;
    addDelay();
}

void logFindParentRecursive(int u) {
    std::cout << "findParent: Recursively finding the parent of node " << u << "\n" << std::endl;
    addDelay();
}

void logParent(int u, bool isParent) {
    if (isParent)
        std::cout << "findParent: Node " << u << " is its own parent." << "\n" << std::endl;
    else
        std::cout << "findParent: Node " << u << " has a different parent." << "\n" << std::endl;
    addDelay();
}

void logUnionByRank(int u, int v) {
    std::cout << "unionByRank: Union of nodes " << u << " and " << v << "\n" << std::endl;
    addDelay();
}

void logUnionAttach(int parent, int child) {
    std::cout << "unionByRank: Attaching node " << child << " under node " << parent << "\n" << std::endl;
    addDelay();
}

void logUnionEqualRank(int parent, int child) {
    std::cout << "unionByRank: Both nodes have the same rank. Attaching node " << child << " under node " << parent << " and increasing the rank." << "\n" << std::endl;
    addDelay();
}

void logStartingKruskal() {
    std::cout << "spanningTree: Starting Kruskal's Algorithm to find MST." << "\n" << std::endl;
    addDelay();
}

void logAddingEdge(int u, int v, int weight) {
    std::cout << "spanningTree: Adding edge (" << u << ", " << v << ") with weight " << weight << " to the priority queue." << "\n" << std::endl;
    addDelay();
}

void logProcessingEdge(int u, int v, int weight) {
    std::cout << "spanningTree: Processing edge (" << u << ", " << v << ") with weight " << weight << "\n" << std::endl;
    addDelay();
}

void logIncludingEdge(int u, int v, int weight) {
    std::cout << "spanningTree: Including edge (" << u << ", " << v << ") in MST." << "\n" << std::endl;
    addDelay();
}

void logSkippingEdge(int u, int v) {
    std::cout << "spanningTree: Skipping edge (" << u << ", " << v << ") as it forms a cycle." << "\n" << std::endl;
    addDelay();
}

void logMSTCost(int cost) {
    std::cout << "spanningTree: Minimum Spanning Tree cost is " << cost << "\n" << std::endl;
    addDelay();
}
