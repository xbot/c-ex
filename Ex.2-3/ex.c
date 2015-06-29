/*
 * Exercise 2·3. Write the function htoi (s ), which converts a string of hexa-
 * decimal digits (including an optional Ox or ox) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

int hexalpha_to_int(char c)
{
    int i;

    for (i = 'a'; i < 'g'; ++i) {
        if (c == i || c == i - 32) {
            return i - 'a' + 10;
        }
    }

    return 0;
}

int pow(int base, int power)
{
    int i, tmp = 1;
    for (i = 0; i < power; ++i) {
        tmp *= base;
    }

    return tmp;
}

int htoi(char hex[], int len)
{
    int i = 0, j = 0, result = 0;

    if (len < 3 || hex[0] != '0' || (hex[1] != 'x' && hex[1] != 'X'))
        return 0;

    while(len > 2) {
        len--;
        if (hex[len] >= '0' && hex[len] <= '9') {
            result += (hex[len] - 48) * pow(16, j);
        } else {
            result += hexalpha_to_int(hex[len]) * pow(16, j);
        }
        j++;
    }

    return result;
}

int main(void)
{
    char hex[MAX_LINE_LEN];
    char c;
    int i = 0;

    while((c = getchar()) != EOF) {
        if (i > MAX_LINE_LEN)
            break;

        if (c == '\n') {
            printf("%d\n", htoi(hex, i));

            for (i = 0; i < MAX_LINE_LEN; ++i) {
                hex[i] = 0;
            }

            i = 0;

            continue;
        }

        hex[i++] = c;
    }

    return 0;
}
