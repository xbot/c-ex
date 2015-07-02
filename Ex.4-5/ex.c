/*
 * Exercise 4-5. Add access to library functions like sin, exp, and pow. See
 * <math •h> in Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
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
    double op1, op2;
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
            case '?':
                printf("top of stack: %f\n", stack[pos-1]);
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'c':
                pos = 0;
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case NAME:
                if (strcmp(s, "sin") == 0) {
                    push(sin(pop()));
                } else if (strcmp(s, "cos") == 0) {
                    push(cos(pop()));
                } else if (strcmp(s, "exp") == 0) {
                    push(exp(pop()));
                } else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else {
                    printf("error: unknown math function.\n");
                }
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

    i = 0;
    if (islower(c)) {
        while(islower(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);
        }
        if (strlen(s) > 1) {
            return NAME;
        } else {
            return c;
        }
    }

    if (!isdigit(c) && c != '.') {
        return c;
    }

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
