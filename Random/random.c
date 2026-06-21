    #include<stdio.h>

    int uadd_ok(unsigned x, unsigned y) {
        unsigned short sum = x + y; 
        return sum >= x;
    }

    int tadd_ok(int x,int y) { 
        int sum = x + y;
        if (x > 0 && y > 0 && sum < 0) return 0;
        if (x < 0 && y < 0 && sum >= 0) return 0;
        return 1;
    }

    int main() {
        
        // unsigned char a = 255;
        // unsigned char b = 1;
        // unsigned short x = 65535;
        // unsigned short y = 2;

        // unsigned char sum = a + b;
        // unsigned short sum_short = x + y;
        // printf("Sum of a and b is : %u\n",sum);
        // printf("Sum of short x and y is : %u \n",sum_short);

        // printf("Uadd OK: %u\n",uadd_ok(x,y));
        
        // short int c = 32767;
        // short int d = 32767;
        // short int sum = c + d;
        // char c = 127;
        // char d = 37;
        // char sum = c + d;
        
        int c = 2147483648;
        int d = 1;
        int sum = c + d;
        printf("Integer C is : %d\n",c);
        printf("Integer D is : %d\n",d);
        printf("Integer Sum is : %d\n",sum);
        printf("Tadd Ok is: %d\n",tadd_ok(c,d));
        
        char x = getchar();
        char *p = &x;
        printf("Address of P is : %x\n",*p);
        printf("Next address is: %x\n",*(p+1));
        printf("the value of EOF is : %d",EOF);
        return 0;
    }