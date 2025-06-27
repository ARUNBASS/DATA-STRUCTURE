#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to enqueue an element
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to dequeue an element
int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

// Breadth First Search function
void BFS(int adjacencyMatrix[MAX][MAX], int n, int startVertex) {
    int i, currentVertex;

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");

    while ((currentVertex = dequeue()) != -1) {
        printf("%d ", currentVertex);

        // Enqueue all adjacent unvisited vertices
        for (i = 0; i < n; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
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

    BFS(adjacencyMatrix, n, startVertex);

    return 0;
}

