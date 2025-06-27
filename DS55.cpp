#include <stdio.h>

#define MAX 30

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to sort edges in increasing order of weights
void sortEdges(struct Edge edges[], int E) {
    struct Edge temp;
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

// Function to find the parent of a node
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void unionSet(int parent[], int x, int y) {
    parent[y] = x;
}

int main() {
    int V, E;
    struct Edge edges[MAX];
    int parent[MAX];
    int i, j, src, dest, weight;
    int count = 0, totalWeight = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Sort edges by weight
    sortEdges(edges, E);

    // Initialize disjoint sets
    for (i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in the Minimum Spanning Tree:\n");

    for (i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int uParent = find(parent, u);
        int vParent = find(parent, v);

        if (uParent != vParent) {
            printf("%d - %d \tWeight: %d\n", u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(parent, uParent, vParent);
            count++;
        }

        if (count == V - 1)
            break;
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}

