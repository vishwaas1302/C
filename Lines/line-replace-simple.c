#include <stdio.h>

int main() {
    int c;
    unsigned char last_was_whitespace = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (last_was_whitespace == 0) {
                putchar(' '); // Print exactly one space for the first blank/tab seen
                last_was_whitespace = 1;
            }
            // If last_was_whitespace == 1, we just skip (continue) automatically
        } else {
            putchar(c);
            last_was_whitespace = 0; // Reset for real letters/newlines
        }
    }
    return 0;
}