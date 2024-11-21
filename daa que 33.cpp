#include <stdio.h>

void insertNumber(int arr[], int *n, int num, int pos) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    (*n)++;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5, num = 10, pos = 3;

    printf("Original List: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    insertNumber(arr, &n, num, pos);

    printf("List after insertion: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
