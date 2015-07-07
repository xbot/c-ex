/*
 * Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
 * accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1000
#define DEFAULTTABWIDTH 4
#define MAXTABSTOPS 10

int getline2(char *s);
void detab(char *s1, char *s2, int tabwidth[]);
void entab(char *s1, char *s2, int tabwidth[]);

int main(int argc, char **argv)
{
    char s1[MAX_LINE_LEN];
    char s2[MAX_LINE_LEN];

    int w[MAXTABSTOPS + 1];
    int i, tab, j;

    if (argc > MAXTABSTOPS)
        argc = MAXTABSTOPS;
    j = 0;
    for (i = 2; i <= argc; ++i) {
        tab = atoi(*++argv);
        if (tab > 0)
            w[j++] = tab;
    }
    if (i == 2)
        w[j++] = DEFAULTTABWIDTH;
    w[j] = 0;

    printf("Usage example: detab 2 4 6\n");

    printf("Input some characters, then press enter:\n");
    while (getline2(s1) == 0);

    detab(s1, s2, w);
    /* entab(s1, s2, w); */
    printf("detab result:\n%s\n", s2);

    return 0;
}

int getline2(char *s)
{
    int c, i, j;

    for (i = 0, j = 0; i < MAX_LINE_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        *s++ = c;
        j++;
    }
    *s = '\0';

    return j;
}

void detab(char *s1, char *s2, int w[])
{
    int j, l, c, blanks, k;

    l = 0;
    k = 0;
    while ((c = *s1++) != '\0') {
        if (c == '\t') {
            if (w[k] == 0)
                k = 0;
            blanks = w[k] - l % w[k];
            k++;
            for (j = 0; j < blanks; ++j) {
                *s2++ = ' ';
                l++;
            }
        } else {
            *s2++ = c;
            l++;
        }
    }
    *s2 = '\0';
}

void entab(char *s1, char *s2, int w[])
{
    int i, j, c, blanks, k;
    int blanksenough;

    i = 0;
    k = 0;
    while ((c = *s1) != '\0') {
        if (c == ' ') {
            blanksenough = 1;
            if (w[k] == 0)
                k = 0;
            blanks = w[k] - i % w[k];
            k++;
            for (j = 1; j < blanks; ++j){
                if (*(s1 + j) != ' ') {
                    blanksenough = 0;
                    break;
                }
            }
            if (blanksenough) {
                *s2++ = '\t';
                s1 += blanks;
                i += blanks;
            } else {
                *s2++ = c;
                i++;
                ++s1;
            }
        } else {
            *s2++ = c;
            i++;
            ++s1;
        }
    }
    *s2++ = '\0';
}
