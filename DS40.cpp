#include <stdio.h>

int main() {
    int arr[] = {2, 5, 2, 8, 5, 6, 8, 8, 2}, n = 9;
    int freq[100] = {0};

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    printf("Repeated Numbers and Their Frequency:\n");
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 1)
            printf("%d appears %d times\n", i, freq[i]);
    }

    return 0;
}

