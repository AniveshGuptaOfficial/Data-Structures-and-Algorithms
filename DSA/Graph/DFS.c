#include <stdio.h>
#include <stdlib.h>
// Node structure for adjacency list representation
struct Node {
    int dest;              // Destination vertex of the edge
    struct Node* next;     // Pointer to the next adjacent vertex
};
// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;     // Pointer to the head node of the list
};
// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
// Recursive helper function for DFS traversal
void DFSRec(struct AdjList adj[], int visited[], int s) {
    visited[s] = 1;             // Mark the current vertex as visited
    printf("%d ", s);           // Print the current vertex
    // Traverse all unvisited adjacent vertices
    struct Node* current = adj[s].head;
    while (current != NULL) {
        int dest = current->dest;
        if (!visited[dest]) {   // Visit adjacent vertex if it hasn't been visited
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}
// Main DFS function to initialize visited array and start traversal
void DFS(struct AdjList adj[], int V, int s) {
    int visited[5] = {0};       // Initialize all vertices as unvisited
    DFSRec(adj, visited, s);    // Start DFS traversal from the source vertex
}
// Function to add an undirected edge to the adjacency list
void addEdge(struct AdjList adj[], int s, int t) {
    // Add edge from s to t
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;
    // Since the graph is undirected, add edge from t to s
    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}
int main() {
    int V = 5;                        // Number of vertices in the graph
    struct AdjList adj[V];            // Array of adjacency lists
    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        adj[i].head = NULL;
    }
    int E = 5;                        // Number of edges in the graph
    int edges[][2] = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};  // Define edges
    // Populate the adjacency list with edges
    for (int i = 0; i < E; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }
    int source = 1;                   // Starting vertex for DFS
    printf("DFS from source: %d\n", source);
    DFS(adj, V, source);              // Perform DFS starting from the source vertex
    return 0;
}
