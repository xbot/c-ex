/*
 * Exercise 5-2. Write getfloat , the floating-point analog of getint . What type does getfloat
 * return as its function value?
 */

#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/* getfloat: get next integer from input into *pn */
int getfloat(double *pn)
{
    int c, sign, nc, power = 0;
    while (isspace(c = getch())); /* skip white space */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        nc = getch();
        if (isdigit(nc))
        {
            c = nc;
        } else {
            ungetch(nc);
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.') {
            power = 1;
        } else {
            *pn = 10.0 * *pn + (c - '0');
            if (power) {
                power *= 10;
            }
        }
    }
    if (power)
    {
        *pn /= power;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    double p;

    getfloat(&p);
    printf("%f\n", p);

    return 0;
}
