/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define TAB_SIZE 4

int get_line(char line[], int maxLen);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i, j;
    int spaces = 0;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        for (i = 0; i < len; ++i) {
            if (line[i] == ' ') {
                spaces++;
            } else {
                for (j = 0; j < spaces/TAB_SIZE; ++j) {
                    putchar('\t');
                }
                for (j = 0; j < spaces%TAB_SIZE; ++j) {
                    putchar(' ');
                }
                putchar(line[i]);
                spaces = 0;
            }
        }

        putchar('\n');

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
