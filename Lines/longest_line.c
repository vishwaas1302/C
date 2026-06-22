#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 50

int getcurrentline(char line[]) {
    int c;
    int line_length = 0;
    int first_char = 0,start_space = 0,trailing_space=0;
    while(((c=getchar()) != EOF) && c != '\n') {
        if(!first_char && (c == ' ' || c == '\t')) {
            start_space++;
        }
        else if(line_length < MAXLINE - 1) {
            line[line_length] = c;
            first_char = 1;
            line_length++;
        }
        else if(line_length == MAXLINE - 1) {
                line[MAXLINE - 1] = '\0';
                printf("%s",line);
                putchar(c);
                line_length++;
        }
        else { 
            putchar(c);
            line_length++;
        }
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

    // Logic for trailing whitespace
    if(line_length > 1 &&  line_length < MAXLINE && (line[line_length-2] == ' ' || line[line_length-2] == '\t')) {
        int len = line_length - 3;
        trailing_space = 1;
        first_char = 0;
        while(!first_char && len > 0) {
            if (line[len] == ' ' || line[len] == '\t') { 
              trailing_space++; 
              len--;
            } 
            else {
                first_char = 1;
            }
       }
         line[len+1] = line[line_length-1];
         line[len+2] = line[line_length];
         line_length = len + 2;
    }
    return line_length;
}

int copy_line(char line[],char longest_line[]) {
    int i = 0;
    while((longest_line[i] = line[i]) != '\0') {
        i++;
    }
}

char* reverse(char line[]) {
    int len=0,i=0;
    int right,left,temp;
    char *reverse_line = malloc(MAXLINE * sizeof(char));
    if(reverse_line == NULL) {
        return NULL;
    }

    while(line[len] != '\0') {
        len++;
    }
    left = 0;
    right = len-1;
    printf("\nReverse line\n");
    len--;
    if(len > 0 && line[right] == '\n') {
        right--;
        len--;
    }
    while(len >= 0) {
        // putchar(line[len]);
        reverse_line[i] = line[len];
        i++;
        len--;
    }
    while(left < right) {
        temp = line[left];
        line[left] = line[right];
        line[right] = temp;
        left++;
        right--;
    }
    printf("\nReverse Line inside Function\n%s",line);
    reverse_line[i] = '\0';
    return reverse_line;
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

    printf("\n Longest line is : %d\n\n %s\n",longest_line_length,longest_line);
    char *rev_line = reverse(longest_line);
    printf("\n%s\n",rev_line);
    return 0;
}