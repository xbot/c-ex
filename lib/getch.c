#include <stdio.h>

#define MAX 100

static char s[MAX];
static int p = 0;

int getch(void) {
    return p ? s[--p] : getchar();
}

void ungetch(int c) {
    if (p < MAX) {
        s[p++] = c;
    } else {
        printf("Error: buf is full.");
    }
}
