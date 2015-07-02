/*
 * Exercise 4-13. Write a recursive version of the function reverse
 * reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINELEN 1000

void reverse(char a[], int from, int len);

int main(void)
{
    char a[] = "ksdfjaksdjfk;asdfjsdf;asdfa";
    reverse(a, 0, strlen(a));
    printf("%s\n", a);
    return 0;
}

void reverse(char a[], int from, int len)
{
    int c;

    if (from >= len / 2) {
        return;
    }

    c = a[from];
    a[from] = a[len - from - 1];
    a[len - from - 1] = c;

    reverse(a, ++from, len);
    a[len] = '\0';
}
