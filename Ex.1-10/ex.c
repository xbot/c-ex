/*
 * Write a program to copy its input to its output, replacing 
 * each tab by \t , each backspace by \b , and each backslash by \\ . 
 * This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(void)
{
    char c;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t\n");
        } else if (c == '\b') {
            printf("\\b\n");
        } else if (c == '\\') {
            printf("\\\\\n");
        } else {
            putchar(c);
        }
    }

    return 0;
}
