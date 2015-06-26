/*
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define FOLD_WIDTH 80

int get_line(char line[], int maxLen);
int find_the_last_blank(char line[], int from, int backSize);
void print_line(char line[], int from, int to);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i, j, k;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        k = FOLD_WIDTH;
        while(k <= len) {
            j = find_the_last_blank(line, k, FOLD_WIDTH);
            if (j) {
                print_line(line, k - FOLD_WIDTH, j);
                k = j + 1 + FOLD_WIDTH;
            } else {
                print_line(line, k - FOLD_WIDTH, k);
                k += FOLD_WIDTH;
            }
        }
        j = k - FOLD_WIDTH;
        if (j < len) {
            while(j < len) {
                putchar(line[j]);
                j++;
            }
            putchar('\n');
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

int find_the_last_blank(char line[], int from, int backSize)
{
    int idx = 0;
    int i;

    for (i = 0; i < backSize; ++i) {
        if (line[from - i] == ' ' || line[from - i] == '\t') {
            idx = from - i;
            break;
        }
    }

    return idx;
}

void print_line(char line[], int from, int to)
{
    int i;

    for (i = 0; i < to - from; ++i) {
        putchar(line[from + i]);
    }
    putchar('\n');
}
