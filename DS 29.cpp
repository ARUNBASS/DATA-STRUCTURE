#include <stdio.h>

// Linear Search
int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int a[50], n, key, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements (sorted for Binary Search):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    i = linearSearch(a, n, key);
    if (i != -1)
        printf("Linear Search: Found at position %d\n", i + 1);
    else
        printf("Linear Search: Not found\n");

    i = binarySearch(a, n, key);
    if (i != -1)
        printf("Binary Search: Found at position %d\n", i + 1);
    else
        printf("Binary Search: Not found\n");

    return 0;
}

