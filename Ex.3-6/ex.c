/*
 * Exercise 3-6. Write a version of i toa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

#define abs(v) (v < 0 ? -(v) : v)

void itoa(int n, char str[], int width);
void reverse(char str[]);

int main(void)
{
    int n = 92347, width = 9;
    char alpha[MAX_LINE_LEN];

    itoa(n, alpha, width);
    reverse(alpha);
    printf("%s\n", alpha);

    return 0;
}

void itoa(int n, char str[], int width)
{
    int delta, i = 0;

    do {
        str[i++] = n % 10 + '0';
    } while((n /= 10) != 0);

    while(i < width) {
        str[i++] = ' ';
    }

    str[i] = '\0';
}

void reverse(char str[])
{
    int i = 0, mid, low = 0;
    char c;

    while (i < MAX_LINE_LEN && str[i] != '\0') {
        i++;
    }

    mid = i / 2;
    i--;
    while(low < mid) {
        c = str[i];
        str[i] = str[low];
        str[low] = c;
        low++;
        i--;
    }
}
