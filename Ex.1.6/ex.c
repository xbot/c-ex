#include <stdio.h>

int main(void)
{
    printf("Press any key.\n\n");
    printf("The key %d is pressed.\n", getchar() != EOF);
    return 0;
}
