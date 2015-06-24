/*
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main(void)
{
    printf("Press any key.\n\n");
    printf("The key %d is pressed.\n", getchar() != EOF);
    return 0;
}
