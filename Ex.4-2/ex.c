/*
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent
 */

#include <stdio.h>

double atof(char str[]);

int main(void)
{
    char *nums[] = {
        "904",
        "1.23e-6",
        "1.3"
    };
    int i;

    for (i = 0; i < 3; ++i) {
        printf("str=%s, num=%f\n", nums[i], atof(nums[i]));
    }

    return 0;
}

double atof(char str[])
{
    double r = 0;
    int i, dec = 0, decPower = 0, decDvr = 1, sign = 1, sci = 0, sciPower = 0, sciSign = 1, sciFactor = 1;

    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (sci) {
                sciPower = sciPower * 10 + str[i] - '0';
            } else {
                r = r * 10 + str[i] - '0';
                if (dec) {
                    decPower++;
                }
            }
        } else if (str[i] == '.') {
            if (dec || sci) {
                printf("Invalid format.\n");
                return 0;
            }
            dec = 1;
        } else if (str[i] == 'e' || str[i] == 'E') {
            if (sci) {
                printf("Invalid format.\n");
                return 0;
            }
            sci = 1;
        } else if (str[i] == '-') {
            if (sci) {
                if (sciSign < 0) {
                    printf("Invalid format.\n");
                    return 0;
                }
                sciSign = -1;
            } else {
                if (sign < 0) {
                    printf("Invalid format.\n");
                    return 0;
                }
                sign = -1;
            }
        } else {
            printf("Invalid format.\n");
            return 0;
        }
    }

    while(decPower-- > 0) {
        decDvr *= 10;
    }
    r /= decDvr;

    while(sciPower-- > 0) {
        sciFactor *= 10;
    }
    r = sciSign > 0 ? r * sciFactor : r / sciFactor;

    return sign > 0 ? r : -(r);
}
