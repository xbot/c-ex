/*
 * Exercise 4-12. Adapt the ideas of printd to write a recursive version of i toa;
 * that is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>
#include <math.h>

#define abs(v) (v < 0 ? -(v) : v)

#define MAX_LINE_LEN 1000

void itoa(int i, char a[]);
void reset_line(char a[]);

int main(void)
{
    int x = 2938472;
    char a[MAX_LINE_LEN];

    reset_line(a);
    itoa(x, a);
    printf("%d, %s\n", x, a);

    return 0;
}

void itoa(int i, char a[])
{
    static j = 0;

    if (i / 10) {
        itoa(i / 10, a);
    } else {
        if (i < 0) {
            a[j++] = '-';
        }
    }
    a[j++] = abs(i) % 10 + '0';
    a[j] = '\0';
}

void reset_line(char line[])
{
    int i = 0;

    while(i < MAX_LINE_LEN && line[i] != '\0') {
        line[i++] = 0;
    }
}
