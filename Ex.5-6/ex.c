/*
 * Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline2
 * (Chapters 1 and 4), atoi, i toa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000

#define abs(v) (v<0 ? -(v) : v)

void getline2(char *line);
long atoi2(const char *alpha);
void itoa2(long i, char *alpha, int base);
void reverse(char *alpha);
int strindex(const char *s, const char *t);

int main(void)
{
    char line[MAX_LINE_LEN];
    char a1[] = "283472";
    char a2[] = "28.3472";
    char num[MAX_LINE_LEN];

    getline2(line);
    printf("%s\n", line);

    printf("a=%s, i=%d\n", a1, atoi2(a1));
    printf("a=%s, i=%d\n", a2, atoi2(a2));

    itoa2(1, num, 10);
    printf("%s\n", num);
    itoa2(12, num, 10);
    printf("%s\n", num);
    itoa2(-12, num, 10);
    printf("%s\n", num);

    char s0[] = "";
    char s1[] = "1";
    char s2[] = "12";
    char s3[] = "123";
    reverse(s0);
    printf("%s\n", s0);
    reverse(s1);
    printf("%s\n", s1);
    reverse(s2);
    printf("%s\n", s2);
    reverse(s3);
    printf("%s\n", s3);

    printf("%d\n", strindex("abc", ""));
    printf("%d\n", strindex("abc", "a"));
    printf("%d\n", strindex("abc", "c"));
    printf("%d\n", strindex("abc", "d"));
    printf("%d\n", strindex("", "abc"));
    printf("%d\n", strindex("a", "abc"));

    return 0;
}

void getline2(char *line)
{
    char c;
    while((c = getchar()) != EOF && c != '\n')
        *line++ = c;
    *line = '\0';
}

long atoi2(const char *alpha)
{
    long i;

    i = 0;
    while(*alpha != '\0') {
        if (!isdigit(*alpha))
            return 0;
        i = i * 10 + *alpha - '0';
        alpha++;
    }

    return i;
}

void itoa2(long i, char *alpha, int base)
{
    long tmp;
    long sign;
    char *origin;

    sign = i;
    origin = alpha;

    do {
        tmp = abs(i % base);
        *alpha++ = tmp + (tmp > 9 ? 'a' : '0');
    } while((i /= base) != 0);

    if (sign < 0)
        *alpha++ = '-';

    *alpha = '\0';
    
    reverse(origin);
}

void reverse(char *alpha)
{
    int low, high, len;
    char c;

    low = high = 0;
    while(*(alpha+high) != '\0') {
        ++high;
    }

    len = high;
    --high;
    while(high > low) {
        c = *(alpha+high);
        *(alpha+high) = *(alpha+low);
        *(alpha+low) = c;
        ++low;
        --high;
    }
    *(alpha+len) = '\0';
}

int strindex(const char *s, const char *t)
{
    int i, j;

    for (i = 0; *(s+i) != '\0'; ++i) {
        for (j = 0; *(t+j) != '\0'; ++j) {
            if (*(t+j) != *(s+i)) {
                break;
            }
        }
        if (j > 0 && *(t+j) == '\0') {
            return i;
        }
    }

    return -1;
}
