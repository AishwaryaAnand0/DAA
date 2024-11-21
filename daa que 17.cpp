#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        if (*max < arr[low]) *max = arr[low];
        if (*min > arr[low]) *min = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    findMaxMin(arr, low, mid, max, min);
    findMaxMin(arr, mid + 1, high, max, min);
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0], min = arr[0];

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}
