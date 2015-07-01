/*
 * Exercise 2-9. In a two's complement number system, x &.= (x-1) deletes the
 * rightmost l-bit in x. Explain why. Use this observation to write a faster ver-
 * sion of bitcount.
 */

/* x-1将x最低位的1变成0，或从高位借位，此时与x按位与，将使低位变0。 */

#include <stdio.h>

int bitcount(unsigned x)
{
    int count = 0;

    while(x > 0) {
        x &= x - 1;
        count++;
    }
    
    return count;
}

int main(void)
{
    unsigned i;

    for (i = 1; i < 10; ++i) {
        printf("x=%u, bit=%d\n", i, bitcount(i));
    }

    return 0;
}
