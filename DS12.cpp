#include <stdio.h>

int main() {
    int a[50], n, key, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number to find: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Number found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Number not found\n");

    return 0;
}

