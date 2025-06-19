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
