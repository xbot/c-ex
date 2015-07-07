/*
 * Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
 * (decreasing) order. Be sure that -r works with -n .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_LINES 100

int readlines(char *linePtrs[], int limit);
int readline(char line[]);
void qsort2 (void *v[], int left, int right, int (*comp) (void *, void *));
void swap (void *v[], int i, int j);
int numcmp (char *s1, char *s2);
int strcmp2 (char *s, char *t);

int numeric = 0;
int reverse = 0;

int main(int argc, char *argv[])
{
    int i, lines;
    char *linePtrs[MAX_LINES];

    for (i = 1; i < argc; ++i) {
        if (*argv[i] == '-') {
            switch (*(argv[i]+1)) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("error: unknown option.\n");
                    return 1;
            }
        }
    }

    while(!(lines = readlines(linePtrs, MAX_LINES)));

    qsort2((void **) linePtrs, 0, lines -1, (int (*)(void *, void *)) (numeric ? numcmp : strcmp2));

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

void qsort2(void *v[], int left, int right, int (*comp) (void *, void *))
{
    int	i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (reverse * (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    qsort2(v, left, last - 1, comp);
    qsort2(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    double	v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp2(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}
