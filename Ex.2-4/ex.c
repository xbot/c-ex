/*
 * Exercise 2-4. Write an alternate version of squeeze (s 1,s2) that deletes
 * each character in s 1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1000

void reset_line(char line[])
{
    int i;

    for (i = 0; i < MAX_LINE_LEN; ++i) {
        line[i] = 0;
    }
}

char* squeeze(char s1[], char s2[])
{
    char *r = calloc(MAX_LINE_LEN, sizeof(char));
    int i = 0, j = 0, k = 0, found = 0;

    while(i < MAX_LINE_LEN && s1[i] != '\0') {
        found = 0;
        for (j = 0; j < MAX_LINE_LEN && s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            r[k++] = s1[i];
        i++;
    }

    return r;
}

int main(void)
{
    char s1[MAX_LINE_LEN], s2[MAX_LINE_LEN];
    char c;
    int lineNum = 0;
    char *result;
    int i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n' || i >= MAX_LINE_LEN) {
            if (lineNum == 0) {
                lineNum++;
                if (i < MAX_LINE_LEN)
                    s1[i] = '\0';
            } else {
                if (i < MAX_LINE_LEN)
                    s2[i] = '\0';
                lineNum = 0;
                result = squeeze(s1, s2);
                printf("%s\n", result);
                free(result);
                reset_line(s1);
                reset_line(s2);
            }
            i = 0;
            continue;
        }

        if (lineNum == 0) {
            s1[i++] = c;
        } else {
            s2[i++] = c;
        }
    }

    return 0;
}
