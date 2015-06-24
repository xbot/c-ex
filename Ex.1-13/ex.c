/*
 * Exercise 1-13. Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */

#include <stdio.h>

#define MAX_WORD_NUM 10

int main(void)
{
    int wordLens[MAX_WORD_NUM];
    int maxLen = 0;
    int wordNum = 0;
    int newWord = 0;
    int i, j, c;

    for (i = 0; i < MAX_WORD_NUM; ++i) {
        wordLens[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if (wordNum >= MAX_WORD_NUM) {
            break;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            if (newWord) {
                if (wordLens[wordNum] > maxLen) {
                    maxLen = wordLens[wordNum];
                }
                newWord = 0;
                wordNum++;
            }
        } else {
            newWord = 1;
            wordLens[wordNum]++;
        }
    }

    for (i = maxLen; i > 0; --i) {
        printf("%4d|", i);
        for (j = 0; j < MAX_WORD_NUM; ++j) {
            c = wordLens[j] >= i ? '*' : ' ';
            printf("%4c", c);
        }
        printf("\n");
    }

    return 0;
}
