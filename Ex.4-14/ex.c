/*
 * Exercise 4-14. Define a macro swap(t,x,y)
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) { t z; z = x; x = y; y = z; }

int main(void)
{
    int a, b;

    a = 1;
    b = 2;
    swap(int, a, b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
