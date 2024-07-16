#include <stdio.h>

int i, j, n, r = -1, f = 0, a[10][10], q[10], visited[10];

void bfs(int u)
{
    int v;
    visited[u] = 1;
    q[++r] = u; 
    while (f <= r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
}

int main()
{
    int source;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the directed graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex (0 to %d):\n", n-1);
    scanf("%d", &source);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    bfs(source);
    printf("From vertex %d the reachable vertices are:\n", source);
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            printf("The node %d is reachable\n", i);
    }
    return 0;
}
