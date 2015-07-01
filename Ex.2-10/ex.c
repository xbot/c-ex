/*
 * Exercise 2-10. Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

void lower(char str[])
{
    int i = 0;

    while(i < MAX_LINE_LEN && str[i] != '\0') {
        str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
        i++;
    }
}

void get_line(char line[])
{
    char c;
    int i = 0;

    while((c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
}

int main(void)
{
    char line[MAX_LINE_LEN];

    while(1) {
        get_line(line);
        lower(line);
        printf("lower=%s\n", line);
    }

    return 0;
}
