#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 9999

int n;
int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
bool visited[MAX_VERTICES];

int findMinDistance() {
    int min = INF;
    int minIndex;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && distance[v] < min) {
            min = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int startVertex) {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[startVertex] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance();
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices (n, max 10): ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix (enter 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    dijkstra(startVertex);

    printf("\nShortest paths from vertex %d to all other vertices:\n", startVertex);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d -> Vertex %d: Distance = %d\n", startVertex, i, distance[i]);
    }

    return 0;
}
