/*
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic parame-
 * ter?
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define TAB_SIZE 4

int get_line(char line[], int maxLen);
int cal_space_size(int offset, int tabsize);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i, j, k;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        for (i = 0; i < len; ++i) {
            if (line[i] == '\t') {
                j = cal_space_size(i, TAB_SIZE);
                for (k = 0; k < j; ++k) {
                    putchar(' ');
                }
            } else {
                putchar(line[i]);
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

int cal_space_size(int offset, int tabsize)
{
    return tabsize - (offset % tabsize);
}
