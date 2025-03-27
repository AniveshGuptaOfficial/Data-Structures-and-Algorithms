#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 6
int bfs(int rGraph[V][V], int s, int t, int parent[]) {
    int visited[V] = {0};
    int q[V], front = 0, rear = 0;
    q[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;
    while (front < rear) {
        int u = q[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return 1;
                }
                q[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return 0;
}
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = path_flow < rGraph[u][v] ? path_flow : rGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main() {
    int graph[V][V];
    printf("Enter the capacity matrix (6x6):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source, sink;
    printf("Enter source vertex (0-5): ");
    scanf("%d", &source);
    printf("Enter sink vertex (0-5): ");
    scanf("%d", &sink);   
    printf("\nThe maximum possible flow is %d\n", 
           fordFulkerson(graph, source, sink));
    return 0;
}
