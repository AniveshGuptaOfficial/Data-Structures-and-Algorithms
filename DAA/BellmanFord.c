#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void BellmanFord(int **graph, int V, int E, int src) {
    int *dis = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dis[graph[j][0]] != INT_MAX && 
                dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) {
            printf("Graph contains negative weight cycle\n");
            free(dis);
            return;
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dis[i] == INT_MAX)
            printf("%d \t\t INFINITY\n", i);
        else
            printf("%d \t\t %d\n", i, dis[i]);
    }
    free(dis);
}
int main() {
    int V, E, src;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    int **graph = (int **)malloc(E * sizeof(int *));
    for (int i = 0; i < E; i++) {
        graph[i] = (int *)malloc(3 * sizeof(int));
    }
    printf("Enter edges in format (u v weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    BellmanFord(graph, V, E, src);
    for (int i = 0; i < E; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
