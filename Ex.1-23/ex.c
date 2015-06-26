/*
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. C com-
 * ments do not nest.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

int get_line(char line[], int maxLen);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i;
    int inComment=0, inQuote=0;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        for (i = 0; i < len; ++i) {
            if (!inComment) {
                if (inQuote || line[i] == '"') {
                    putchar(line[i]);
                }
                if (line[i] == '"') {
                    inQuote = !inQuote;
                    continue;
                }
            }

            if (!inQuote) {
                if (inComment) {
                    if (line[i] == '*' && line[i+1] == '/') {
                        inComment = 0;
                        i++;
                    }
                } else {
                    if (line[i] == '/' && line[i+1] == '*') {
                        inComment = 1;
                        i++;
                    } else {
                        putchar(line[i]);
                    }
                }
            }
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
