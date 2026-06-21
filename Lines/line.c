#include<stdio.h>

int main() {
    int c;
    int space = 0,tab = 0,line = 0;
    while( (c = getchar()) != EOF ) {
        putchar(c);
        switch (c) {
            case ' ':
                ++space;
                break;
            ;;
            case '\t':
                ++tab;
                break;
            ;;
            case '\n':
                ++line;
                break;
            ;;
            default: 
              break;
            ;;
        }
    }

    printf("\nSpace are: %d\n",space);
    printf("\nTabs are: %d\n",tab);
    printf("\nLines are: %d\n",line);
    return 0;
}