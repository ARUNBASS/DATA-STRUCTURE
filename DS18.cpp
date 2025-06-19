#include <stdio.h>

int main() {
    int reg[50], n, i, search, found = 0;

    printf("Enter number of registration numbers: ");
    scanf("%d", &n);

    printf("Enter registration numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &reg[i]);

    printf("Enter registration number to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (reg[i] == search) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Registration number %d found at position %d\n", search, i + 1);
    else
        printf("Registration number %d not found\n", search);

    return 0;
}

