/*
 * Exercise 2-5. Write the function any (s 1, s2 ), which returns the first location
 * in the string s 1 where any character from the string s2 occurs, or -1 if s 1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.)
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

int any(char s1[], char s2[])
{
    int i = 0, j = 0;

    while(i < MAX_LINE_LEN && s1[i] != '\0') {
        for (j = 0; j < MAX_LINE_LEN && s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
        i++;
    }

    return -1;
}

int main(void)
{
    char s1[MAX_LINE_LEN], s2[MAX_LINE_LEN];
    char c;
    int lineNum = 0;
    int i = 0, result;

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
                result = any(s1, s2);
                printf("%d\n", result);
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
