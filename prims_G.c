#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int n;
int cost[MAX_VERTICES][MAX_VERTICES];
int f[MAX_VERTICES][2];
int sum = 0;

void prim() {
    int selected[MAX_VERTICES] = {false};
    int numSelected = 0;
    int x, y;

    selected[0] = true;
    numSelected++;

    while (numSelected < n) {
        int min = 999;
        int u, v;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] != 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        selected[v] = true;
        f[numSelected - 1][0] = u;
        f[numSelected - 1][1] = v;
        numSelected++;
        sum += cost[u][v];
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

    prim();
    printf("\nPrim's algorithm:\n");
    printf("Minimum spanning tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d -> %d\n", f[i][0], f[i][1]);
    }
    printf("Total cost = %d\n", sum);

    return 0;
}
