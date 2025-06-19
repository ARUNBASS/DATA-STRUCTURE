#include <stdio.h>

int main() {
    int a[50], n, i, key, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element %d found at position %d (index %d)\n", key, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element %d not found\n", key);

    return 0;
}

