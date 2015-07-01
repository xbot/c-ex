/*
 * Exercise 4-1. Write the function strrindex
 * (s, t), which returns the position
 * of the rightmost occurrence of t in s, or - 1 if there is none.
 */

#include <stdio.h>

int strrindex(char s[], char t[]);

int main(void)
{
    char s[] = "dkjbflasjfhsjdkhfshdfksajdfhskdjfhkasjdhfsd";
    char t[] = "hfs";

    printf("%d\n", strrindex(s, t));

    return 0;
}

int strrindex(char s[], char t[])
{
    int i = 0, j, idx = -1, found = 0;

    while(s[i] != '\0') {
        j = 0;
        found = 1;
        while(t[j] != '\0') {
            if (s[i + j] == '\0' || t[j] != s[i + j]) {
                found = 0;
                break;
            }
            j++;
        }
        if (found) {
            idx = i;
        }
        i++;
    }

    return idx;
}
