#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
        cout << "Factorial not defined for negative numbers.";
    else {
        for (int i = 1; i <= n; i++)
            fact *= i;
        cout << "Factorial of " << n << " = " << fact;
    }

    return 0;
}

