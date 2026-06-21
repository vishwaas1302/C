#include <stdio.h>

void printBag(int *bag, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", bag[i]);
    }
    printf("}\n");
}

void generate_powerset(int *input, int n, int index, int *current_bag, int bag_size) {
    if (index == n) {
        printBag(current_bag, bag_size);
        return;
    }

    // Choice 1: Include input[index]
    current_bag[bag_size] = input[index];
    generate_powerset(input, n, index + 1, current_bag, bag_size + 1);

    // Choice 2: Exclude input[index]
    generate_powerset(input, n, index + 1, current_bag, bag_size);
}

int main() {
    int my_set[] = {1, 2, 3};
    int n = 3;
    int current_bag[3]; // Buffer to hold the current subset

    printf("Generating Powerset for {1, 2, 3, 4, 5}:\n");
    generate_powerset(my_set, n, 0, current_bag, 0);

    return 0;
}