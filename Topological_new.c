#include <stdio.h>

void DFS(int);

int Q[10], F = 0, R = 0;
int A[10][10], vis[10], EXP[10], J = 0;
int n, m;

int main()
{
    int v, u;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            A[i][j] = 0;
        }
    }
    printf("Enter the number of edges\n");
    scanf("%d", &m);
    printf("Enter the edges\n");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        A[u][v] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i);
        }
    }

    printf("Topological traversal\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", EXP[i]);
    }
}

void DFS(int v)
{
    int i;
    vis[v] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (A[v][i] == 1 && vis[i] == 0)
        {
            DFS(i);
        }
    }
    EXP[J++] = v;
}
