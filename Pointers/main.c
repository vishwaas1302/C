#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    printf("\n\nShowing bytes:\n\n");
    printf("Address of Start: %p\n", &start);
    int *new = &start;
    printf("Value of Start: %x\n",*new);
    for (i = 0; i < (int)len; i++)
    {
        printf("\nAddress: %p \t Value: %.2x \n", start + i, start[i]);
        // printf("\n");
    }
}

void check_endianess(int* start) {
    printf("\n\nChecking Endianess:\n\n");
    printf("The number is: %d\n", *start);
    printf("Hex of number is : %.8x\n", *start);

    printf("The first byte is: %.2x\n", *((unsigned char*)start));

    if (*(unsigned char*)start == (*start & 0XFF)) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}

void show_int(int y) {
    printf("\n\nInteger\n\n");
    printf("Address of variable 'y' is: %p\n", &y);
    show_bytes((byte_pointer) &y, sizeof(int));
}

void show_float(float x) {
    printf("\n\nFloat\n\n");
    printf("Address of variable 'x' is: %p\n", &x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    printf("\n\nPointer\n\n");
    printf("Address of pointer variable: %p\n", &x);
    printf("Address stored in pointer variable: %p\n", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void dtob(int num) {
    int rem,i=0;
    printf("\nDecimal to Binary for %d \n",num);
    while(num > 0) {
        rem = num % 2;
        printf("Bit - %d is: %d\n",i,rem);
        num = num / 2;
        i = i +1;
    }
    
}

void dtobbit(int num) {
    printf("\nDecimal to Binary for %d \n",num);

    for(int i =0; i<(sizeof(num)*8);i++) {
        int mask = 1<<i;
        if ((num & mask) > 0) {
            printf("Bit %d is : %d\n",i,1);
        }
        else
        {
            printf("Bit %d is : %d\n",i,0);
        }
        
    }
}

int main() {
    int val = -12345;
    float f = 12345.0;
    int *p = &val; 

    printf("\n\nThe Address of variable 'val' is: %p\n", &val);
    printf("The Address of p is: %p\n", &p);
    printf("The value stored in pointer variable p is: %p\n\n", p);

    show_int(val);
    show_float(f);
    show_pointer(p);

    // int *ptr = (int *)88;
    check_endianess(&val);
    dtob(12345);
    dtobbit(12345);
    return 0;
}

