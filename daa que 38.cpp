#include <stdio.h>
#include <limits.h>

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}};

int minCost(int n) {
    int mask = 0, cost = 0;

    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0 && costMatrix[i][j] < min) {
                min = costMatrix[i][j];
            }
        }
        cost += min;
        mask |= (1 << i);
    }
    return cost;
}

int main() {
    printf("Minimum cost: %d\n", minCost(N));
    return 0;
}
