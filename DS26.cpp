#include <stdio.h>
#include <limits.h>

#define V 4  // Number of cities

int tsp(int graph[V][V], int visited[], int currPos, int count, int cost, int start) {
    if (count == V && graph[currPos][start] != 0)
        return cost + graph[currPos][start];

    int ans = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currPos][i] != 0) {
            visited[i] = 1;
            int temp = tsp(graph, visited, i, count + 1, cost + graph[currPos][i], start);
            if (temp < ans) ans = temp;
            visited[i] = 0;
        }
    }
    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[V] = {0};
    visited[0] = 1; // start from city 0

    int result = tsp(graph, visited, 0, 1, 0, 0);
    printf("Minimum cost of TSP: %d\n", result);
    return 0;
}

