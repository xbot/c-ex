/*
 * Exercise 3-5. Write the function i tob (n, s ,b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * i tob ( n, s, 16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

#define abs(v) (v < 0 ? -(v) : v)

void itob(int n, int b, char str[]);
void reverse(char line[]);

int main(void)
{
    int n = -94372, b = 16;
    char str[1000];

    itob(n, b, str);
    reverse(str);
    printf("%s\n", str);

    return 0;
}

void itob(int n, int b, char str[])
{
    int delta, i = 0, sign = n;
    do {
        delta = abs(n % b);
        if (delta <= 9) {
            str[i++] = delta + '0';
        } else {
            str[i++] = delta - 10 + 'a';
        }
        printf("%d\n", delta);
    } while((n /= b) != 0);

    if (sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';
}

void reverse(char line[])
{
    int i = 0, mid, low = 0;
    char c;

    while(i < MAX_LINE_LEN && line[i] != '\0') {
        i++;
    }
    mid = i / 2;
    i--;
    while(low < mid) {
        c = line[i];
        line[i] = line[low];
        line[low] = c;
        low++;
        i--;
    }
}
