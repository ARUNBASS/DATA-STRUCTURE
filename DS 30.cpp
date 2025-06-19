#include <stdio.h>

int main() {
    int a[50], n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n >= 5)
        printf("5th iterated element: %d\n", a[4]);
    else
        printf("Array has less than 5 elements\n");

    return 0;
}

