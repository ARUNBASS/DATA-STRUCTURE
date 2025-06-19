#include <stdio.h>

int main() {
    int a[50], n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Even numbers:\n");
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);

    printf("\nOdd numbers:\n");
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            printf("%d ", a[i]);

    return 0;
}

