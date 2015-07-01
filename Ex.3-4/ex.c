/*
 * Exercise 3-4. In a two's complement number representation, our version of
 * i toa does not handle the largest negative number, that is, the value of n equal
 * to _(2wordsize-l). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

#define abs(v) (v < 0 ? -(v) : v)

void itoa(int n, char alpha[]);
void reverse(char alpha[]);

int main(int argc, char *argv[])
{
    int n = -10000;
    /* int n = -1; */
    char alpha[MAX_LINE_LEN];

    itoa(n, alpha);
    reverse(alpha);
    printf("%s\n", alpha);

    return 0;
}

void itoa(int n, char alpha[])
{
    int sign = n;
    int i = 0;

    do {
        alpha[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);

    if (sign < 0) {
        alpha[i++] = '-';
    }

    alpha[i] = '\0';
}

void reverse(char alpha[])
{
    int i = 0, low = 0, mid;
    char c;

    while(i < MAX_LINE_LEN && alpha[i] != '\0') {
        i++;
    }

    i--;
    mid = i / 2;
    while(low < mid) {
        c = alpha[i];
        alpha[i] = alpha[low];
        alpha[low] = c;
        low++;
        i--;
    }
}
