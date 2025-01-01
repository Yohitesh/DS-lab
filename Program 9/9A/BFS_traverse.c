#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming undirected graph
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(graph, visited, start, vertices);

    return 0;
}
