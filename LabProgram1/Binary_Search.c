#include <stdio.h>

int BinarySearch(int array[], int low, int high, int element) {
    if (high >= low) {
        int middle = low + (high - low) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] > element)
            return BinarySearch(array, low, middle - 1, element);
        return BinarySearch(array, middle + 1, high, element);
    }
    return -1;
}

int main() {
    int array[30], n, element, i;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for the number of elements.\n");
        return 1; 
    }
    printf("Enter the elements in sorted order: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input for array element.\n");
            return 1; 
        }
    }

    printf("Enter key value: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid input for key value.\n");
        return 1; 
    }

    int found = BinarySearch(array, 0, n - 1, element); 

    if (found == -1)
        printf("Element is not found in array.\n");
    else
        printf("Element found at index: %d\n", found);

    return 0;
}
