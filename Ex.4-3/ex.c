/*
 * Exercise 4-3. Given the basic framework, it's straightforward to extend the cal-
 * culator. Add the modulus (%) operator and provisions for negative numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int pos = 0;
double stack[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero devisor.\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero devisor.\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f)
{
    if (pos < MAXVAL) {
        stack[pos++] = f;
    } else {
        printf("error: stack overflow.\n");
    }
}

double pop(void)
{
    if (pos > 0) {
        return stack[--pos];
    } else {
        printf("error: stack empty.\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        return c;
    }

    i = 0;
    if (isdigit(c)) {
        while((isdigit(s[++i] = c = getch())));
    }
    if (c == '.') {
        while((isdigit(s[++i] = c = getch())));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > BUFSIZE) {
        printf("error: buffer overflow.\n");
    } else {
        buf[bufp++] = c;
    }
}
