#include <stdio.h>
#define MAX 10
#define INF 9999

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the shortest distances
void printSolution(int dist[], int n, int startVertex) {
    printf("Vertex\tDistance from Source %d\n", startVertex);
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int n, int startVertex) {
    int dist[MAX];
    int visited[MAX];

    // Initialize distances and visited[]
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        // Update distance value of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, startVertex);
}

int main() {
    int n, graph[MAX][MAX];
    int i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    dijkstra(graph, n, startVertex);

    return 0;
}

