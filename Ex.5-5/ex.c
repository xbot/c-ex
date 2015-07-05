/*
 * Exercise 5-5. Write versions of the library functions strncpy2 , strncat , and strncmp , which
 * operate on at most the first n characters of their argument strings. For example,
 * strncpy2(s,t,n) copies at most n characters of t to s . Full descriptions are in Appendix B.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000

char *strncpy2(char *s, const char *t, int n);
char *strncat2(char *s, const char *t, int n);
int strncmp2(const char *s, const char *t, int n);

int main(void)
{
    char s[MAX_LINE_LEN] = "skhdfkjsdfsdfjlskfjs";
    const char *t = "29837428364527834628384753";

    strncpy2(s, t, 10);
    printf("%s\n", s);

    strncat2(s, t, 10);
    printf("%s\n", s);

    printf("%d\n", strncmp2("abc", "ab", 2));
    printf("%d\n", strncmp2("abc", "ab", 3));
    printf("%d\n", strncmp2("Abc", "ab", 3));
    printf("%d\n", strncmp2("abc", "Ab", 3));

    return 0;
}

char *strncpy2(char *s, const char *t, int n)
{
    size_t i;

    for (i = 0; i < n && t[i] != '\0'; ++i)
    {
        s[i] = t[i];
    }
    for (; i < n; ++i)
    {
        s[i] = '\0';
    }

    return s;
}

char *strncat2(char *s, const char *t, int n)
{
    size_t i, j;

    i = j = 0;

    while(s[i] != '\0')
        ++i;

    while(n-- > 0 && (s[i++] = t[j++]) != '\0');

    return s;
}

int strncmp2(const char *s, const char *t, int n)
{
    size_t i;

    for (i = 0; n > 0 && s[i] == t[i] && s[i] != '\0'; ++i, --n);

    if (n == 0 || s[i] == t[i])
        return 0;
    if ((unsigned char)s[i] > (unsigned char) t[i])
        return 1;
    return -1;
}
