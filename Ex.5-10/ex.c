/*
 * Exercise 5-10. Write the program expr , which evaluates a reverse Polish expression from the
 * command line, where each operator or operand is a separate argument. For example,
 * expr 2 3 4 + *
 * evaluates 2 * (3+4).
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000

double buffer[BUF_SIZE];
int bp = 0;
void push(double o);
double pop();

#define NOTHING 1000
#define NUMBER 1001
int get_op_type(char s[]);

int main(int argc, char *argv[])
{
    int i;
    double op;

    for (i = 1; i < argc; ++i) {
        switch (get_op_type(argv[i])) {
            case NUMBER:
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op = pop();
                push(pop() / op);
                break;
            default:
                printf("error: unknown operand.\n");
        }
    }

    printf("%f\n", pop());

    return 0;
}

void push(double o)
{
    if (bp < BUF_SIZE) {
        buffer[bp++] = o;
    } else {
        printf("error: buffer overflow.\n");
    }
}

double pop()
{
    if (bp > 0) {
        return buffer[--bp];
    } else {
        printf("error: buffer empty.\n");
        return 0;
    }
}

int get_op_type(char s[])
{
    int i, period, num;

    if (strlen(s) == 1) {
        switch (s[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                return s[0];
                break;
        }
    }

    for (i = 0, period = 0, num = 0; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) {
            ++num;
        } else if (s[i] == '.') {
            if (period || !num) {
                return NOTHING;
            } else {
                ++period;
            }
        } else if (s[i] == '-') {
            if (num) {
                return NOTHING;
            }
        } else {
            return NOTHING;
        }
    }

    if (num) {
        return NUMBER;
    } else {
        return NOTHING;
    }
}
