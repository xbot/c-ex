/*
 * Write a function reverse (s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

int get_line(char line[], int maxLen);
void reverse(char line[], int len);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        reverse(line, len);
        printf("%d: %s\n", len, line);
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

void reverse(char line[], int len)
{
    int i;
    char c;

    for (i = 0; i < len/2; ++i) {
        c = line[i];
        line[i] = line[len-1-i];
        line[len-1-i] = c;
    }
}
