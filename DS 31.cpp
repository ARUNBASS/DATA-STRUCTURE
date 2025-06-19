#include <stdio.h>

int main() {
    int a[50], n, total = 0, sum = 0;

    printf("Enter size of array (n-1 elements for 1 to n): ");
    scanf("%d", &n);

    printf("Enter elements (from 1 to %d, with 1 missing):\n", n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    total = n * (n + 1) / 2;
    printf("Missing element: %d\n", total - sum);

    return 0;
}

