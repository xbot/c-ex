/*
 * Write a program to print all input lines that are longer than 80
 * characters.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
/* #define MIN_LINE_LEN 80 */
#define MIN_LINE_LEN 3

int get_line(char line[], int maxLen);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len;
    int i;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        if (len > MIN_LINE_LEN) {
            printf("%d: %s\n", len, line);
        }
        for (i = 0; i < MAX_LINE_LEN; ++i) {
            line[i] = 0;
        }
    }

    return 0;
}

int get_line(char line[], int maxLen)
{
    int i = 0;
    char c;

    while(i < maxLen && (c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        i++;
    }

    return i;
}
