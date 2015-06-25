/*
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

float f2c(float f)
{
    return (5.0/9.0) * (f-32.0);
}

int main(void)
{
    float f=0, maximum=300, step=20;

    while(f <= maximum) {
        printf("%.2fF = %.2fC\n", f, f2c(f));
        f += step;
    }

    return 0;
}
