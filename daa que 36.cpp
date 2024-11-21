#include <stdio.h>

void containerLoading(int weights[], int n, int capacity) {
    int currentLoad = 0;

    printf("Selected weights: ");
    for (int i = 0; i < n; i++) {
        if (currentLoad + weights[i] <= capacity) {
            printf("%d ", weights[i]);
            currentLoad += weights[i];
        }
    }
    printf("\nTotal load: %d\n", currentLoad);
}

int main() {
    int weights[] = {10, 20, 30, 40, 50};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 100;

    containerLoading(weights, n, capacity);
    return 0;
}
