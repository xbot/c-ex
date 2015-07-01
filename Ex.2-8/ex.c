/*
 * Exercise 2-8. Write a function rightrot(x,n)
 * that returns the value of the
 * integer x rotated to the right by n bit positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    while(n > 0) {
        if (x & 1) {
            x = (x >> 1) | ~(~0 >> 1);
        } else {
            x = x >> 1;
        }
        n--;
    }
    return x;
}

int main(void)
{
    unsigned x;
    int n;

    for (x = 0; x < 10; ++x) {
        for (n = 1; n < 8; ++n) {
            printf("x=%u, n=%d, result=%u\n", x, n, rightrot(x, n));
        }
    }

    return 0;
}
