#include <stdio.h>

typedef struct {
    int value, weight;
    float ratio;
} Item;

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float knapsack(Item items[], int n, int capacity) {
    sortItems(items, n);
    float totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n = 3, capacity = 50;
    Item items[] = {{60, 10, 0}, {100, 20, 0}, {120, 30, 0}};

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Maximum value in Knapsack: %.2f\n", knapsack(items, n, capacity));
    return 0;
}
