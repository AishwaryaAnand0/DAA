#include <stdio.h>

int isPrime(int n, int i) {
    if (n <= 2) return (n == 2);
    if (n % i == 0) return 0;
    if (i * i > n) return 1;
    return isPrime(n, i + 1);
}

void generatePrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i, 2)) printf("%d ", i);
    }
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Prime numbers: ");
    generatePrimes(limit);
    return 0;
}
