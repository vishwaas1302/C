#include<stdio.h>
#define OUT 0
#define IN 1
int main()  { 

    int c,nc,nw,nl,state;
    nc = nw = nl = 0;
    state = OUT;

    while((c = getchar()) != EOF ) {
        ++nc;
        if(c == ' ' || c == '\t' || c == '\n' ) { 
            if(c == '\n') {
                ++nl;
            }
            
            if(state == IN) putchar('\n');
            state = OUT;
        }
        else if(state == OUT) {
            ++nw;
            state = IN;
        }
        
        if (c != ' ' && c != '\t' && c != '\n') putchar(c);
    }

    printf("\n Number of Characters: %d\n",nc);
    printf("\n Number of Words: %d\n",nw);
    printf("\n Number of Lines: %d\n",nl);
    return 0;
}