#include <stdio.h>

void swap(int *x,int *y) {
    printf("\nAddress of X: %p\t Value: %d\n", &x, *x);
    printf("\nAddress of Y: %p\t Value: %d\n", &y, *y);
    
    *y = *x ^ *y;
    printf("\nAfter Swap - 1\n");
    printf("\nValue of X: %d\n", *x);
    printf("\nValue of Y: %d\n", *y);
    
    *x = *x ^ *y;
    printf("\nAfter Swap - 2\n");
    printf("\nValue of X: %d\n", *x);
    printf("\nValue of Y: %d\n", *y);
    
    *y = *x ^ *y;
    printf("\nAfter Swap - 3\n");
    printf("\nValue of X: %d\n", *x);
    printf("\nValue of Y: %d\n", *y);
    
}

void reverse_array(int a[],int size) {
    int first=0,last=size-1;
    for(;first<last;first++,last--) {
        swap(&a[first],&a[last]);
    }

    printf("\n%d\t %d\t\n",first,last);
}

void print_array(int a[],int size) {
    printf("\nArray: ");
    for(int i=0;i<size;i++) {
        printf("%d ",a[i]);
    }
}

int main() { 
    // int first=10,second=20;
    // swap(&first,&second);
    int some_array[] = {1,2,3,4,5};
    int size = sizeof(some_array)/sizeof(some_array[0]);
    reverse_array(some_array,size);
    print_array(some_array,size); 
    return 0;
}