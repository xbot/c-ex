/*
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>

int binsearch(int x, int list[], int size)
{
    int low = 0, high = size -1;
    int mid;

    mid = (low + high) / 2;
    while(low <= high && list[mid] != x) {
        if (x < list[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    if (list[mid] == x) {
        return mid;
    } else {
        return -1;
    }
}

int main(void)
{
    int list[] = {1,2,3,4,5};
    int i;

    for (i = 0; i < 6; ++i) {
        printf("%d\n", binsearch(i, list, 5));
    }

    return 0;
}
