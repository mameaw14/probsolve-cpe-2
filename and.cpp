#include<stdio.h>
main() {
    int a = 0x799FEEEE;
    int b = 0x799EFFFF;
    printf("and 0x%x, or 0x%x, xor 0x%x, nor 0x%x", a&b, a|b, a^b, ~(a|b) );
}