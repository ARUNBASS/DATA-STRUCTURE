#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 1, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int freq[n], i, j, count;

    for (i = 0; i < n; i++)
        freq[i] = -1;

    for (i = 0; i < n; i++) {
        if (freq[i] == -1) {
            count = 1;
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }

    printf("Elements repeated twice:\n");
    for (i = 0; i < n; i++) {
        if (freq[i] == 2)
            printf("%d\n", arr[i]);
    }
    return 0;
}

