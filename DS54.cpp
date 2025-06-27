#include <stdio.h>
#define MAX 10
#define INF 9999

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX][MAX], int n) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

// Prim's Algorithm
void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];  // Stores constructed MST
    int key[MAX];     // Key values to pick minimum weight edge
    int mstSet[MAX];  // To represent set of vertices in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is always the root

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int n, graph[MAX][MAX];
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;  // No edge treated as INF
        }
    }

    primMST(graph, n);

    return 0;
}

