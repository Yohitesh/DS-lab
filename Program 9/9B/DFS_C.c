#include <stdio.h>
#include <stdlib.h>

void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int vertices) {
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, vertices);
        }
    }
}

int isConnected(int graph[MAX][MAX], int vertices) {
    int visited[MAX] = {0};

    dfs(graph, visited, 0, vertices);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX][MAX] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming undirected graph
    }

    if (isConnected(graph, vertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
