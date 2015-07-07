/*
 * Exercise 5-12. Extend entab and detab to accept the shorthand
 * entab -m +n
 * to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
 * default behavior.
 */

/* 抄作业 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1000
#define DEFAULTSTARTCOL 1
#define DEFAULTTABWIDTH 4
#define MAXTABSTOPS 10

int getline2(char *s);
void detab(char *s1, char *s2, int startcol, int tabwidth);
void entab(char *s1, char *s2, int startcol, int tabwidth);

int main(int argc, char **argv)
{
    char s1[MAX_LINE_LEN];
    char s2[MAX_LINE_LEN];

    int m, n, m2, n2;

    m = DEFAULTSTARTCOL;
    n = DEFAULTTABWIDTH;

    while (--argc > 0) {
        argv++;
        if (**argv == '-') {
            if ((m2 = atoi(++*argv)) > 0)
                m = m2;
        } else if (**argv == '+') {
            if ((n2 = atoi(++*argv)) > 0)
                n = n2;
        }
    }
    
    printf("Usage example: entab -2 +8\n");

    printf("Input some characters, then press enter:\n");
    while (getline2(s1) == 0);

    detab(s1, s2, m, n);
    /* entab(s1, s2, m, n); */
    printf("result:\n%s\n", s2);

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

void detab(char *s1, char *s2, int col, int w)
{
    int j, l, c, blanks;

    l = 0;
    while ((c = *s1++) != '\0') {
        if (c == '\t') {
            blanks = w - l % w;
            if (l >= col - 1) {
                for (j = 0; j < blanks; ++j) {
                    *s2++ = ' ';
                    l++;
                }
            } else {
                *s2++ = c;
                l += blanks;
            }
        } else {
            *s2++ = c;
            l++;
        }
    }
    *s2 = '\0';
}

void entab(char *s1, char *s2, int col, int w)
{
    int i, j, c, blanks;
    int blanksenough;

    i = 0;
    while ((c = *s1) != '\0') {
        if (c == ' ' && i >= col - 1) {
            blanksenough = 1;
            blanks = w - i % w;
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
        } else if (c == '\t') {
            *s2++ = c;
            i += w - i % w;
            ++s1;
        } else {
            *s2++ = c;
            i++;
            ++s1;
        }
    }
    *s2++ = '\0';
}
