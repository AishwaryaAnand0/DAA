#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversed[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}
