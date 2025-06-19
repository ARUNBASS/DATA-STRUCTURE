#include <stdio.h>

void sort(int a[], int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((order == 1 && a[j] > a[j + 1]) || (order == 2 && a[j] < a[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[50], n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Sorted in Ascending order:\n");
    sort(a, n, 1);
    display(a, n);

    printf("Sorted in Descending order:\n");
    sort(a, n, 2);
    display(a, n);

    return 0;
}

