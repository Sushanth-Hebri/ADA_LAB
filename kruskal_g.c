#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int n, parent[MAX_VERTICES];
int f[MAX_VERTICES][2];
int cost[MAX_VERTICES][MAX_VERTICES];
int sum = 0;

void unionn(int a, int b) {
    int i = find(a);
    int j = find(b);
    if (i != j) {
        parent[j] = i;
    }
}

int find(int a) {
    while (parent[a] != a) {
        a = parent[a];
    }
    return a;
}

void kruskal() {
    int count = 0;
    int k = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (count != n - 1) {
        int min = 999;
        int u, v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int x = find(u);
        int y = find(v);

        if (x != y) {
            f[k][0] = u;
            f[k][1] = v;
            k++;
            count++;
            sum += cost[u][v];
            unionn(x, y);
        }

        cost[u][v] = cost[v][u] = 999;
    }
}

int main() {
    printf("Enter the number of vertices (n, max 10): ");
    scanf("%d", &n);

    printf("Enter the edges (adjacency matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal();
    printf("\nKruskal's algorithm:\n");
    printf("Minimum spanning tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d -> %d\n", f[i][0], f[i][1]);
    }
    printf("Total cost = %d\n", sum);

    return 0;
}
