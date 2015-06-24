/*
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

int main(void)
{
    char c;
    int newWord = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (newWord) {
                putchar('\n');
                newWord = 0;
            }
        } else {
            putchar(c);
            newWord = 1;
        }
    }

    return 0;
}
