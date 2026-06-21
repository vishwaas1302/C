#include<stdio.h>
#define MAXLINE 30

int getcurrentline(char line[]) {
    int c;
    int line_length = 0;
    while(((c=getchar()) != EOF) && c != '\n') {
        if(line_length < MAXLINE - 1) {
            line[line_length] = c;
        }
        else if(line_length == MAXLINE - 1) {
                line[MAXLINE - 1] = '\0';
                printf("%s",line);
                putchar(c);
        }
        else { 
            putchar(c);
        }
        line_length++;
    }
    if(c == '\n') {
        if(line_length < MAXLINE - 1) {
            line[line_length] = c;
            line_length++;
        }
        else {
            putchar('\n');
        }
    }
    if(line_length < MAXLINE) {
        line[line_length] = '\0';
    }
    return line_length;
}

int copy_line(char line[],char longest_line[]) {
    int i = 0;
    while((longest_line[i] = line[i]) != '\0') {
        i++;
    }
}

int main() {
    char line[MAXLINE],longest_line[MAXLINE];
    unsigned int longest_line_length=0,current_line_length=0;
    while((current_line_length = getcurrentline(line)) != 0) {
        if(current_line_length > longest_line_length) {
            longest_line_length = current_line_length;
            copy_line(line,longest_line);
        }
    }

    printf("\n Longest line is : %d\n\n %s",longest_line_length,longest_line);
    return 0;
}