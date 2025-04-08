#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
struct Edge { 
    int src, dest, weight; 
}; 
void BellmanFord(int vertices, int edges, struct Edge edgeList[], int source){ 
    int distance[vertices]; 
    for (int i = 0; i < vertices; i++) { 
        distance[i] = INT_MAX; 
    } 
    distance[source] = 0; 
    for (int i = 0; i < vertices - 1; i++) { 
        for (int j = 0; j < edges; j++) { 
            int u = edgeList[j].src; 
            int v = edgeList[j].dest; 
            int weight = edgeList[j].weight; 
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]){ 
                distance[v] = distance[u] + weight; 
            } 
        } 
    } 
    for (int j = 0; j < edges; j++) { 
        int u = edgeList[j].src; 
        int v = edgeList[j].dest; 
        int weight = edgeList[j].weight; 
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) { 
            printf("Graph contains negative weight cycle!\n"); 
            return; 
        } 
    }  
    printf("Vertex Distance from Source %d:\n", source); 
    for (int i = 0; i < vertices; i++) { 
        if (distance[i] == INT_MAX) 
            printf("Vertex %d: INF\n", i); 
        else 
            printf("Vertex %d: %d\n", i, distance[i]); 
    } 
} 
int main() { 
    int vertices, edges, source; 
    printf("Enter number of vertices: "); 
    scanf("%d", &vertices); 
    printf("Enter number of edges: "); 
    scanf("%d", &edges); 
    struct Edge edgeList[edges]; 
    printf("Enter edges (source destination weight):\n"); 
    for (int i = 0; i < edges; i++){ 
        scanf("%d %d %d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].weight); 
    } 
    printf("Enter source vertex: "); 
    scanf("%d", &source); 
    BellmanFord(vertices, edges, edgeList, source); 
    return 0; 
} 