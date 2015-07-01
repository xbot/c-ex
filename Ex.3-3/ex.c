/*
 * Exercise 3-3. Write a function expand (s 1, s2) that expands shorthand nota-
 * tions like a - z in the string s 1 into the equivalent complete list abc ... xyz in
 * s2. Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

void expand(char s1[], char s2[]);
void get_line(char line[]);

int main(void)
{
    char s1[MAX_LINE_LEN], s2[MAX_LINE_LEN];

    get_line(s1);
    expand(s1, s2);
    printf("s1=%s\ns2=%s\n", s1, s2);

    return 0;
}

void get_line(char line[])
{
    int i = 0;
    char c;

    while((c = getchar()) != EOF && c != '\n' && i < MAX_LINE_LEN) {
        line[i++] = c;
    }
    line[i] = '\0';
}

void expand(char s1[], char s2[])
{
    int i = 0, j = 0;
    char c;

    while((c = s1[i++]) != '\0') {
        if (s1[i] != '\0' && s1[i+1] != '\0' && s1[i] == '-' && s1[i+1] >= c) {
            while(c <= s1[i+1]) {
                s2[j++] = c++;
            }
            i += 2;
        } else {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}
