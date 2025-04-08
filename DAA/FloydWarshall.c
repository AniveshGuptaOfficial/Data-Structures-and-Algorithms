#include <stdio.h> 
#include <limits.h> 
#define INF 99999 
#define V 100      
void printSolution(int dist[][V], int vertices); 
void floydWarshall(int graph[][V], int vertices) { 
int dist[V][V];
for (int i = 0; i < vertices; i++){ 
    for (int j = 0; j < vertices; j++){ 
        dist[i][j] = graph[i][j]; 
    } 
}  
    for (int k = 0; k < vertices; k++){ 
        for (int i = 0; i < vertices; i++){ 
            for (int j = 0; j < vertices; j++){ 
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) { 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
    printSolution(dist, vertices); 
} 
void printSolution(int dist[][V], int vertices){ 
    printf("All-pairs shortest distances:\n"); 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            if (dist[i][j] == INF) 
                printf("INF "); 
            else 
                printf("%d ", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
int main() { 
    int vertices; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &vertices); 
    int graph[V][V]; 
    printf("Enter the adjacency matrix (use %d for INF):\n", INF); 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            scanf("%d", &graph[i][j]); 
        } 
    }    
    floydWarshall(graph, vertices); 
    return 0; 
} 