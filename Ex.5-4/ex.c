/*
 * Exercise 5-4. Write the function strend(s,t) , which returns 1 if the string t occurs at the
 * end of the string s , and zero otherwise.
 */

#include <stdio.h>

int strend(char *s, char *t);

int main(void)
{
    char *s = "ksdjfsldkfjsldfsds";
    char *t1 = "sds";
    char *t2 = "sd";
    char *t3 = "0ksdjfsldkfjsldfsds";

    printf("s=%s, t=%s, result=%d\n", s, t1, strend(s, t1));
    printf("s=%s, t=%s, result=%d\n", s, t2, strend(s, t2));
    printf("s=%s, t=%s, result=%d\n", s, t3, strend(s, t3));

    return 0;
}

int strend(char *s, char *t)
{
    int sLen, tLen, i, j;

    sLen = strlen(s);
    tLen = strlen(t);

    if (sLen < tLen)
    {
        return 0;
    }

    for (i = sLen - 1, j = tLen - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (s[i] != t[j])
        {
            return 0;
        }
    }

    return 1;
}
