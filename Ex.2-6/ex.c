/*
 * Exercise 2-6. Write a function setbits(x,p,n,y)
 * that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & (~0 << (p + 1)) | (~(~0 << (p + 1 - n))) | (~(~0 << n) & y) << (p + 1 - n);
}

int main(void)
{
    unsigned x, y;
    int p, n;

    for (x = 0; x < 10; ++x) {
        for (y = 0; y < 10; ++y) {
            for (p = 0; p < 16; ++p) {
                for (n = 0; n <= p + 1; ++n) {
                    printf("x=%u, y=%u, p=%d, n=%d, result=%u, result2=%u\n", x, y, p, n, setbits(x, p, n, y), setbits2(x, p, n, y));
                }
            }
        }
    }
    return 0;
}
