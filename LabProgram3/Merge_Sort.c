#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 30000

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int a[MAXSIZE], i, nk;
    clock_t start, end;
    double runtime;

    printf("Enter the size of the array (up to %d): ", MAXSIZE);
    if (scanf("%d", &nk) != 1 || nk < 1 || nk > MAXSIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    srand(time(NULL));
    printf("Randomly generated array:\n");
    for (i = 0; i < nk; i++) {
        a[i] = rand() % 10000;
        printf("%d ", a[i]);
    }
    printf("\n");

    start = clock();
    mergeSort(a, 0, nk - 1);
    end = clock();
    runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < nk; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Time taken for sorting is %0.6lf seconds\n", runtime);
    return 0;
}
