#include <stdio.h>

void print_binary(int n) {
    int i;
    printf("\nBinary representation of %d is: ", n);
    for (i = 15; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
        
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Hex of %d is: %.4X\n", n,n);
}


char* equal(int x,int y) {
    return (!(x ^ y) ? "True" : "False");
}

int main() {

    int status = 9, poison_mask = 8;
    print_binary(status);
    print_binary(poison_mask);

    int new_status = status & poison_mask;
    printf("\nStatus & Poison_Mask: %d \t HEX: %.4X\n",new_status,new_status);
    print_binary(new_status);

    new_status = 1 & poison_mask;
    printf("\nStatus & Poison_Mask: %d \t HEX: %.4X\n",new_status,new_status);
    print_binary(new_status);

    return 0;
}