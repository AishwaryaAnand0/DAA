#include <stdio.h>

float optimalBST(float p[], int n) {
    float cost[n][n], sum[n][n];

    for (int i = 0; i < n; i++) {
        cost[i][i] = p[i];
        sum[i][i] = p[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = __FLT_MAX__;
            sum[i][j] = sum[i][j - 1] + p[j];

            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum[i][j];

                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    float p[] = {0.2, 0.3, 0.1, 0.4};
    int n = sizeof(p) / sizeof(p[0]);

    printf("Optimal cost of BST: %.2f\n", optimalBST(p, n));
    return 0;
}
