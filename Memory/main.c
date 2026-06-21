#include <stdio.h>
#include <stdlib.h>

int main() { 
    char *start;
    int something = 100;
    char name[10]= "Vishwaas";
    start = malloc(1024);

    if (start == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    char *large_string = "This is much the same as before, except that fahr and celsius are declared to be float and the formula for conversion is written in a more natural way. We were unable to use 5/9 in the previous version because integer division would truncate it to zero. A decimal point in a constant indicates that it is floating point, however, so 5.0/9.0 is not truncated because it is the ratio of two floating-point values.";
    
    snprintf(start,1024, "%s", large_string);
    printf("Value of start is: %p\n", &start);
    printf("Memory allocated at address: %p\n", start);
    printf("\nThe value at allocated memory is: %s\n\n\n", start);
    printf("The address of variable 'name' is: %p\n", &name);
    printf("The value of variable 'name' is: %s\n", name);
    printf("The value of variable 'something' is: %d\n", something);
    printf("The address of variable 'something' is: %p\n", &something);

    start = 0x55fc04ad72a0;
    printf("\nThe value at address 0x55fc04ad72a0 is: %s\n", start);
}