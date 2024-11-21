#include <stdio.h>

void subsetSum(int set[], int subset[], int n, int subsetSize, int total, int sum, int index) {
    if (total == sum) {
        printf("Subset: ");
        for (int i = 0; i < subsetSize; i++) printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        subset[subsetSize] = set[i];
        subsetSum(set, subset, n, subsetSize + 1, total + set[i], sum, i + 1);
    }
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int subset[100];
    int sum = 35;

    subsetSum(set, subset, n, 0, 0, sum, 0);
    return 0;
}
