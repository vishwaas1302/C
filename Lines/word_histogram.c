#include<stdio.h>
#define OUT 0
#define IN 1
#define MAX_WORD_LENGTH 16

int main() { 

    int c,state,max,wlen,wcount[MAX_WORD_LENGTH];
    wlen = state = max = OUT;

    for(int i = 0; i < MAX_WORD_LENGTH; i++) wcount[i] = 0;

    while((c = getchar()) != EOF ) { 
        if(c == ' ' ||  c == '\t' || c == '\n') { 
            if(state == IN) {
                if(wlen >= MAX_WORD_LENGTH) {
                    wcount[MAX_WORD_LENGTH-1]++;
                }
                else {
                    wcount[wlen]++;
                }
                state = OUT;
            }
            wlen = 0;
        }
        else { 
            state = IN;
            wlen++;
        }
    }

    for(int i = 0; i < MAX_WORD_LENGTH; i++) {
        if((wcount[i]) > max) max = wcount[i];
    }

    printf("\nWord Cont Table\n");
    printf("\nWord Length \t\t Word Count\n");
    for(int i = 1; i < MAX_WORD_LENGTH; i++) { 
        if(i==MAX_WORD_LENGTH-1) {
            printf("\n%3d+\t%3d\t",i,wcount[i]);
        }
        else {
            printf("\n%3d\t%3d\t",i,wcount[i]);
        }

        for(int j = 0;j < wcount[i]; j++) {
            printf("*");
        }
        putchar('\n');
    }

    printf("\n\n Histogram \n\n");
    for(int i = max; i > 0 ; i--) {
        printf(" %d\t|",i);
         for(int j = 1; j<MAX_WORD_LENGTH; j++) {
            if(wcount[j] >= i) {
                printf("  *  ");
            }
            else {
                printf("     ");
            }    
        }
        printf("\n");
    }
    for(int j = 0;j<MAX_WORD_LENGTH;j++) {
            printf("------");
    }
    printf("\n\t ");    
    for(int j = 1;j<MAX_WORD_LENGTH;j++) {
        printf(" %3d ",j);
    }
    printf("\n\n");
    return 0;
}