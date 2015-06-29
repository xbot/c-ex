/*
 * Exercise 2-2 discusses a for loop from the text. Here it is:
 * for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 */

#include <stdio.h>

#define MAX_STR_LEN 100

int main(void)
{
    char s[MAX_STR_LEN];
    int i = 0;
    char c;

    while(i < MAX_STR_LEN) {
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            break;
        } else {
            s[i++] = c;
        }
    }

    s[i] = '\0';

    return 0;
}
