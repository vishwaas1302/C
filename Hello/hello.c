#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int first = 10;
    char second = 'A';
    double third = 3.14;

    printf("Integer: %d\n", first);
    printf("Character: %c\n", second);
    printf("Double: %.2f\n", third);

    printf("The address of Integer variable 'first' is: %p\n",&first);
    printf("The address of Character variable 'second' is: %p\n",&second);
    printf("The address of Double variable 'third' is: %p\n",&third);
    return 0;
}