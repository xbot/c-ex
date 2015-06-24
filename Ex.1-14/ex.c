/*
 * Exercise 1-14. Write a program to print a histogram of the frequencies of dif-
 * ferent characters in its input.
 */

#include <stdio.h>

#define MAX_CHARS 256

int main(void)
{
    int charFreqs[MAX_CHARS];
    int i, j, c, maxFreq=0;

    for (i = 0; i < MAX_CHARS; ++i) {
        charFreqs[i] = 0;
    }

    while((c = getchar()) != EOF) {
        charFreqs[c]++;
        if (charFreqs[c] > maxFreq) {
            maxFreq = charFreqs[c];
        }
    }

    for (j = maxFreq; j > 0; --j) {
        printf("%4d|", j);
        for (i = 0; i < MAX_CHARS; ++i) {
            c = charFreqs[i] >= j ? '*' : ' ';
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
