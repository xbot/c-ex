/*
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

int get_line(char line[], int maxLen);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        for (i = len-1; i >= 0; --i) {
            if (line[i] == ' ' || line[i] == '\t') {
                line[i] = 0;
                len--;
            } else {
                break;
            }
        }
        printf("%d: %s\n", len, line);
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
