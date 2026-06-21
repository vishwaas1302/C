#include<stdio.h>

int main() {
    int c;
    unsigned char last_space = 0, last_tab = 0;
    
    while((c = getchar()) != EOF ) {
        // Print only if the character is not space or its the first space encountered
        if(last_space == 0 || ( c != ' ') ) {
            
            // Handle tabs
            if (c == '\t') {
                if(last_space == 1) continue; // if previous character was space or tab then continue;
                putchar(' '); // else print just one space for the first tab
                last_space = 1; 
                continue;
            }
            else {
                putchar(c); // If not tab then print character and reset last space;
            }
        }

        if(c == ' ') {
            // Set last space if current character is space;
            last_space = 1; 
        }
        else {
            last_space = 0;
        }                       
    }

    return 0;
}

