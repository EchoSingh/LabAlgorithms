#include <stdio.h>

int parent[10] = {0};

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionVertices(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int mincost = 0, cost[10][10], n, i, j, ne = 1, a, b, min, u, v;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of the minimum spanning tree are:\n");
    while (ne < n) {
        for (min = 999, i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (unionVertices(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("The minimum cost of the spanning tree is %d\n", mincost);
    return 0;
}
