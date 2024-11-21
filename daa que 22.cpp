#include <stdio.h>

int binomialCoeff(int n, int k) {
    int dp[k + 1];
    for (int i = 0; i <= k; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = (k < i ? k : i); j > 0; j--) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[k];
}

int main() {
    int n = 5, k = 2;
    printf("C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
