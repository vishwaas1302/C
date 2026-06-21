#include <stdio.h>

void print_binary(int n) {
    printf("\nBinary representation of %d is: ", n);
    unsigned int mask = 1u << (sizeof(int) * 8 - 1);
    for (int i = 0; i < (int)sizeof(int) * 8; i++) {
        printf("%c", (n & mask) ? '1' : '0');
        if ((i + 1) % 4 == 0) printf(" ");
        mask >>= 1;
    }
    printf("\n");
    printf("Hex of %d is: %.8X\n", n,n);
}

void print_bytes(unsigned char *byte, size_t size) {
    printf("\nPrinting Bytes....\n");
    
    for(int i=0; i<(int)size; i++) {
        printf("\n Address: %p \t Byte - %d: %.2X \n",(byte+i),4-i,*(byte+i));
        print_binary(((int)*(byte+i)));
    }

}

int uadd_ok(unsigned x, unsigned y) {
    return ((x + y >= x));
}
int tadd_ok(int x,int y) {
    int sum = x + y;
    printf("\nSum is : %d\n",sum);
    if (((x>0) && (y>0) && (sum <= 0)) || ((x<0) && (y<0) && (sum >= 0))) {
        printf("\nTwo's Overflow\n");
        print_binary(sum);
        return 0;
    }
    else
    {
        printf("\nNo Overflow\n");
        print_binary(sum);
        return 1;
    }
}

int div16(int x)
{
    int bias = (x>>31) & 0xF;
    return (x + bias) >> 4;
}

int tmul_ok(int x, int y)
{
    __int64_t result = (__int64_t)x * (__int64_t)y;
    return ((int)result  == (__int64_t)result ? 1:0); 
}

int main() { 
    unsigned int x = 2147483648; // 2^31
    unsigned int y = 4294967295; // 2^32 - 1
    unsigned int z = 53191;
    float f = 1.0;
    unsigned w = 10;
    printf("X is %u and Y is %u\n", x, y);
    
    print_binary(x);
    print_binary(y);
    print_binary(z);

    print_bytes((unsigned char *)&f,sizeof(f));
    
    unsigned a = w * -1;
    print_binary(a);

    int of = uadd_ok(0,0);
    printf("\n%d\n",of);

    tadd_ok(-1,-2147483648);
    return 0;
}