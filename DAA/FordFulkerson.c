#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
struct Graph {
    int V;
    int **capacity;
};
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->capacity = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->capacity[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->capacity[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(struct Graph* graph, int u, int v, int capacity) {
    graph->capacity[u][v] = capacity;
}
bool bfs(struct Graph* graph, int s, int t, int parent[]) {
    int V = graph->V;
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph->capacity[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                queue[rear++] = v;
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}
int fordFulkerson(struct Graph* graph, int s, int t) {
    int V = graph->V;
    struct Graph* residualGraph = createGraph(V);
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            residualGraph->capacity[u][v] = graph->capacity[u][v];
        }
    }
    int parent[V];
    int max_flow = 0;
    while (bfs(residualGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (residualGraph->capacity[u][v] < path_flow) {
                path_flow = residualGraph->capacity[u][v];
            }
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph->capacity[u][v] -= path_flow;
            residualGraph->capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    for (int i = 0; i < V; i++) {
        free(residualGraph->capacity[i]);
    }
    free(residualGraph->capacity);
    free(residualGraph);
    return max_flow;
}
int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (source destination capacity):\n");
    for (int i = 0; i < E; i++) {
        int u, v, cap;
        scanf("%d %d %d", &u, &v, &cap);
        addEdge(graph, u, v, cap);
    }
    int s, t;
    printf("Enter source node: ");
    scanf("%d", &s);
    printf("Enter sink node: ");
    scanf("%d", &t);
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, s, t));
    for (int i = 0; i < V; i++) {
        free(graph->capacity[i]);
    }
    free(graph->capacity);
    free(graph);
    return 0;
}