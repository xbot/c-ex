/*
 * Revise the main routine of the longest-line program so it will correctly print the length of
 * arbitrarily long input lines, and as much as possible of the text.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

int get_line(char line[], int maxLen);
void copy_line(char from[], char to[]);

int main(void)
{
    char line[MAX_LINE_LEN], longestLine[MAX_LINE_LEN];
    int len, maxLen=0;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        if (len > maxLen) {
            maxLen = len;
            copy_line(line, longestLine);
        }
    }

    if (maxLen > 0) {
        printf("Longest line is:\n%d: %s\n", maxLen, longestLine);
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

void copy_line(char from[], char to[])
{
    int i = 0;

    while((to[i] = from[i]) != '\0') {
        i++;
    }
}
