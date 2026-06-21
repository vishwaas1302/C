#include <stdio.h>

int main() { 

    char anothername[5];
    int something=100;
    char name[5];
    float fahrenheit, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    scanf("%s",name);
    printf("Entered name is : %s\n", name);
    
    printf("Fahrenheit to Celsius conversion table:\n");
    printf("-----------------------------------\n");
    printf("| Fahrenheit  \t | Celsius \t  | \n");
    printf("-----------------------------------\n");
    
    fahrenheit = lower; 
    while(fahrenheit <= upper) { 
        celsius = (5.0/9.0) * (fahrenheit - 32);
        printf("| %.0f \t\t | %6.1f \t  | \n", fahrenheit,celsius);
        fahrenheit = fahrenheit + step;
    }

    printf("-----------------------------------\n");
    
    scanf("%s",anothername);
    printf("Entered another name is : %s\n", anothername);

    printf("The value of variable 'something' is: %d\n", something);
    printf("lower: %.2f, upper: %.2f, step: %.2f\n", lower, upper, step);
    printf("The address of variable 'name' is: %p\n", &name);
    printf("The address of variable 'anothername' is: %p\n", &anothername);
    printf("The address of variable 'something' is: %p\n", &something);
    printf("The address of variable 'lower' is: %p\n", &lower);
    printf("The address of variable 'upper' is: %p\n", &upper);
    printf("The address of variable 'step' is: %p\n", &step);

    printf("The value of variable 'name' is: %s\n", name);
    
    return 0;
}