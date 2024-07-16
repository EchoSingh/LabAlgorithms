#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 30000
#define NTIMES 5000

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    while (1) {
        while (i <= high && a[i] <= pivot) i++;
        while (j >= low && a[j] > pivot) j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            int temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int main() {
    int a[MAXSIZE], temp[MAXSIZE], i, n;
    clock_t start, end;
    double runtime = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    srand(1);
    printf("Randomly generated array:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int k = 0; k < NTIMES; k++) {
        // Copy the original array for sorting
        for (i = 0; i < n; i++) {
            temp[i] = a[i];
        }

        start = clock();
        quicksort(temp, 0, n - 1);
        end = clock();
        
        runtime += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    runtime /= NTIMES;

    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("Average time taken for sorting is %0.6lf seconds\n", runtime);

    return 0;
}
