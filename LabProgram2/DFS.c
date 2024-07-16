#include <stdio.h>
#include <stdlib.h>

int n, a[10][10], visited[10];

void dfs(int u) {
    int v;
    visited[u] = 1;
    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int i, j, source;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(0); 

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Vertex %d is not reachable from vertex 0\n", i);
            printf("So the graph is not connected.\n");
            return 0;
        }
    }

    printf("The graph is connected.\n");
    return 0;
}
