/*
 * Exercise 5-13. Write the program tail , which prints the last n lines of its input. By default, n
 * is set to 10, let us say, but it can be changed by an optional argument so that
 * tail -n
 * prints the last n lines. The program should behave rationally no matter how unreasonable the
 * input or the value of n. Write the program so it makes the best use of available storage; lines
 * should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
 * fixed size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_LINES 100

int readlines(char *linePtrs[], int limit);
int readline(char line[]);

int main(int argc, char *argv[])
{
    int limit, i, lines;
    char *linePtrs[MAX_LINES];

    if (argc > 1) {
        limit = atoi(argv[1]);
    } else {
        limit = 10;
    }

    while(!(lines = readlines(linePtrs, limit)));

    for (i = 0; i < lines; ++i) {
        printf("line%d: %s\n", i+1, linePtrs[i]);
    }

    return 0;
}

int readlines(char *linePtrs[], int limit)
{
    int i;
    char line[MAX_LINE_LEN];
    char *p;

    i = 0;
    while (i < limit && readline(line) != EOF) {
        p = calloc(MAX_LINE_LEN, sizeof(char));
        strcpy(p, line);
        linePtrs[i++] = p;
    }

    return i;
}

int readline(char line[])
{
    int i, c;

    i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    if (c == EOF && !i) {
        return EOF;
    } else {
        return i;
    }
}
