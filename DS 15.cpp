#include <stdio.h>

int main() {
    int a[50], b[50], c[100], n1, n2, i, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    // Merging arrays
    for (i = 0; i < n1; i++)
        c[k++] = a[i];
    for (i = 0; i < n2; i++)
        c[k++] = b[i];

    printf("Merged Array:\n");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);

    return 0;
}

