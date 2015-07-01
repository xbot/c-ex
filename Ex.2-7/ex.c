/*
 * Exercise 2-7. Write a function invert(x,p,n)
 * that returns x with the n bits
 * that begin at position p inverted (i.e., I changed into 0 and vice versa), leaving
 * the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << p);
}

int main(void)
{
    unsigned x;
    int p, n;

    for (x = 0; x < 10; ++x) {
        for (p = 0; p < 16; ++p) {
            for (n = 0; n < p + 1; ++n) {
                printf("x=%u, p=%d, n=%d, result=%u\n", x, p, n, invert(x, p, n));
            }
        }
    }

    return 0;
}
