#include <stdio.h>
#define MAX 10

int visited[MAX];

// DFS function
void DFS(int adjacencyMatrix[MAX][MAX], int n, int vertex) {
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(adjacencyMatrix, n, i);
        }
    }
}

int main() {
    int n, adjacencyMatrix[MAX][MAX];
    int i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(adjacencyMatrix, n, startVertex);
    printf("\n");

    return 0;
}

