#include <stdio.h>
#include <stdlib.h>
int x[10];

int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nqueens(int k, int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printf("\nSolution is:\n");
                for (j = 1; j <= n; j++)
                    printf("%d\t", x[j]);
                printf("\n");
                for (j = 1; j <= n; j++) {
                    for (int l = 1; l <= n; l++) {
                        if (x[j] == l)
                            printf("Q%d\t", j);
                        else
                            printf("*\t");
                    }
                    printf("\n");
                }
            } else {
                nqueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n == 2 || n == 3) {
        printf("No solutions.\n");
    } else {
        nqueens(1, n);
    }
    return 0;
}
