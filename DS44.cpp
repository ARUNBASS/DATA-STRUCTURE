#include <stdio.h>

int main() {
    char arr[] = "programming";
    int n = sizeof(arr) - 1;

    printf("Repeated characters with their indices:\n");

    for (int i = 0; arr[i] != '\0'; i++) {
        for (int j = i + 1; arr[j] != '\0'; j++) {
            if (arr[i] == arr[j]) {
                printf("'%c' at index %d and %d\n", arr[i], i, j);
                break;
            }
        }
    }
    return 0;
}

