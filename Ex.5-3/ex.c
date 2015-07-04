/*
 * Exercise 5-3. Write a pointer version of the function strcat2 that we showed in Chapter 2:
 * strcat2(s,t) copies the string t to the end of s .
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcat2(char **s, char *t);

int main(void)
{
    char *s = "ksdjfklasdjfkl;sdjfksdjfs";
    char *t = "2893472893472983472";

    strcat2(&s, t);
    printf("%s\n", s);

    return 0;
}

void strcat2(char **s, char *t)
{
    int len, i, j;
    char *newStr;

    len = strlen(*s) + strlen(t);
    newStr = malloc((len+1) * sizeof(char));
    for (i = 0; i < strlen(*s); ++i) {
        newStr[i] = (*s)[i];
    }
    for (j = 0; j < strlen(t); ++j) {
        newStr[i++] = t[j];
    }
    newStr[i] = '\0';

    /* free(s); */
    *s = newStr;
}
