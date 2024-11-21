#include <stdio.h>

int reverseNumber(int num) {
    int reverse = 0;
    while (num != 0) {
        reverse = reverse * 10 + (num % 10);
        num /= 10;
    }
    return reverse;
}

int main() {
    int num = 12345;
    printf("Original number: %d\n", num);
    printf("Reversed number: %d\n", reverseNumber(num));
    return 0;
}
