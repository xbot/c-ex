/*
 * Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is the pro-
 * gram?
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINES 3
#define MAX_LINE_LEN 1000

void readlines2(char lines[][MAX_LINE_LEN]);
void readlines(char *linesptr);
void getline2(char *line);

int main(void)
{
    char lines[MAX_LINES][MAX_LINE_LEN];
    int i;

    readlines((char *)lines);
    /* readlines2(lines); */
    for (i = 0; i < MAX_LINES; ++i) {
        if (strlen(lines[i]) == 0)
            break;
        printf("line%d: %s\n", i+1, lines[i]);
    }

    return 0;
}

void getline2(char *line)
{
    int i, c;

    for (i = 0; i < MAX_LINE_LEN && (c = getchar()) != EOF && c != '\n'; ++i)
        *(line+i) = c;
    *(line+i) = '\0';
}

void readlines2(char lines[][MAX_LINE_LEN])
{
    int i;

    for (i = 0; i < MAX_LINES; ++i) {
        getline2(lines[i]);
        if (strlen(lines[i]) == 0)
            break;
    }
}

void readlines(char *linesptr)
{
    int i;

    for (i = 0; i < MAX_LINES; ++i, linesptr += MAX_LINE_LEN) {
        getline2(linesptr);
        if (strlen(linesptr) == 0)
            break;
    }
}
