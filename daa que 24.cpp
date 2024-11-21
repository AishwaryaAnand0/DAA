#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) sum += i;
    }
    return (sum == num);
}

int main() {
    int num = 28;
    if (isPerfect(num))
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is not a Perfect Number\n", num);

    return 0;
}
