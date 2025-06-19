#include <stdio.h>
#include <limits.h>

int reverse(int n) {
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        if (rev > INT_MAX/10 || rev < INT_MIN/10)
            return 0;  // Overflow case
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed: %d\n", reverse(num));
    return 0;
}

