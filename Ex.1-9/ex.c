/*
 * Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(void)
{
    char c;
    int gotBlank = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' && !gotBlank) {
            putchar(c);
            gotBlank = 1;
        }
        if (c != ' ') {
            gotBlank = 0;
            putchar(c);
        }
    }

    return 0;
}
