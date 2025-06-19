#include <stdio.h>

int main() {
    int a[3][3], b[3][3], result[3][3] = {0}, i, j, k;

    printf("Enter 3x3 Matrix A:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("Enter 3x3 Matrix B:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                result[i][j] += a[i][k] * b[k][j];

    printf("Result:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int a[100], n, i, pos, val, ch;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    do {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Pos & Val: ");
            scanf("%d%d", &pos, &val);
            for (i = n; i >= pos; i--) a[i] = a[i - 1];
            a[pos - 1] = val; n++;
        }
        else if (ch == 2) {
            printf("Position to delete: ");
            scanf("%d", &pos);
            for (i = pos - 1; i < n; i++) a[i] = a[i + 1];
            n--;
        }
        else if (ch == 3) {
            for (i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
        }
    } while (ch != 4);

    return 0;
}

