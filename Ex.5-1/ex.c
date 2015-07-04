/*
 * Exercise 5-1. As written, getint treats a + or - not followed 
 * by a digit as a valid representation of zero. Fix it to push 
 * such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, nc;
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
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    int p;

    getint(&p);
    printf("%d\n", p);

    return 0;
}
