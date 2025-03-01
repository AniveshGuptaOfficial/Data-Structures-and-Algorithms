#include <stdio.h>
#include <stdlib.h>
// Comparator function to sort edges by weight in ascending order
int comparator(const void* p1, const void* p2) 
{ 
    const int(*x)[3] = p1; 
    const int(*y)[3] = p2; 
    // Compare the weights of the edges
    return (*x)[2] - (*y)[2]; 
} 
// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        parent[i] = i;  // Initially, each vertex is its own parent
        rank[i] = 0;    // Rank is 0 initially
    } 
} 
// Function to find the parent of a node using path compression
int findParent(int parent[], int component) 
{ 
    // If the node is its own parent, return the node
    if (parent[component] == component) 
        return component;
    // Otherwise, recursively find the parent of the current node and apply path compression
    return parent[component] = findParent(parent, parent[component]); 
} 
// Function to unite two sets using union by rank
void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
    // Find the parents of the two nodes
    u = findParent(parent, u); 
    v = findParent(parent, v); 

    // If the rank of u is less than the rank of v, make v the parent of u
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } 
    // If the rank of v is less than the rank of u, make u the parent of v
    else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } 
    // If the ranks are the same, make one node the parent of the other and increment the rank of the new parent
    else { 
        parent[v] = u; 
        rank[u]++; 
    } 
} 
// Function to find the Minimum Spanning Tree (MST) using Kruskal's Algorithm
void kruskalAlgo(int n, int edge[n][3]) 
{ 
    // Sort the edges by weight (using the comparator function)
    qsort(edge, n, sizeof(edge[0]), comparator); 
    int parent[n]; 
    int rank[n]; 
    // Initialize parent[] and rank[] arrays
    makeSet(parent, rank, n); 
    // To store the minimum cost of the MST
    int minCost = 0; 
    printf("Following are the edges in the constructed MST:\n"); 
    // Iterate through the edges and build the MST
    for (int i = 0; i < n; i++) { 
        int v1 = findParent(parent, edge[i][0]); 
        int v2 = findParent(parent, edge[i][1]); 
        int wt = edge[i][2]; 
        // If the parents are different, it means the vertices are in different sets, so union them
        if (v1 != v2) { 
            unionSet(v1, v2, parent, rank, n); 
            minCost += wt; 
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt); 
        } 
    } 
    // Output the minimum cost of the MST
    printf("Minimum Cost Spanning Tree: %d\n", minCost); 
} 
// Driver code to test the implementation
int main() 
{ 
    // Define edges with format {vertex1, vertex2, weight}
    int edge[5][3] = { { 0, 1, 10 }, { 0, 2, 6 }, { 0, 3, 5 }, { 1, 3, 15 }, { 2, 3, 4 } }; 
    // Call Kruskal's algorithm to find the MST
    kruskalAlgo(5, edge); 
    return 0; 
}
