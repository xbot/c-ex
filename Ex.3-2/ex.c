/*
 * Exercise 3-2. Write a function escape (s, t) that converts characters like
 * newline and tab into visible escape sequences like \n and \ t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

void escape(char s[], char t[])
{
    int i, j;

    for (i = 0, j = 0; i < MAX_LINE_LEN && t[i] != '\0' && j < MAX_LINE_LEN; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

void get_line(char line[])
{
    int i = 0;
    char c;

    while((c = getchar()) != EOF) {
        line[i++] = c;
    }
    line[i] = '\0';
}

int main(void)
{
    char s[MAX_LINE_LEN], t[MAX_LINE_LEN];

    get_line(t);
    escape(s, t);
    printf("%s\n", s);

    return 0;
}
