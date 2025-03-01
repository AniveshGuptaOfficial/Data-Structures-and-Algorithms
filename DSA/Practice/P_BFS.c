#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
void bfs(int adj[MAX][MAX],int V,int S){
    int q[MAX],f=0,r=0;
    bool v[MAX]={false};
    v[S]=true;
    q[r++]=S;
    while (f<r){
        int c = q[f++];
        printf("%d ",c);
        for(int i=0;i<V;i++){
            if(adj[c][i]==1 && !v[i]){
                v[i]=true;
                q[r++]=i;
            }
        }
    }
    
}
void addEdge(int adj[MAX][MAX],int u,int v){
    adj[u][v]=1;
    adj[v][u]=1;
}
int main() {
    int adj[MAX][MAX] = {0};   
    int V = 5;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    printf("BFS starting from vertex 0:\n");
    bfs(adj, V, 0);
    return 0;
}