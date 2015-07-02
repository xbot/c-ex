/*
 * Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOFis pushed back,
 * then implement your design.
 */

/*
 * char类型不要求值是signed还是unsigned，在不同的机器上与int转换时
 * 处理方式不同，要正确处理EOF (-1)，就把char类型改成int
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
int buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char []);

int main(void)
{
    int type, i, var;
    double op1, op2;
    char s[MAXOP];
    double vars[26];
    double v;

    for (i = 0; i < 26; ++i) {
        vars[i] = 0.0;
    }

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
                v = pop();
                printf("\t%.8g\n", v);
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
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z') {
                    vars[var - 'A'] = pop();
                } else {
                    printf("error: invalid variable name.\n");
                }
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(vars[type - 'A']);
                    var = type;
                } else if (type == 'v') {
                    push(v);
                    var = type;
                } else {
                    printf("error: unknown command %s\n", s);
                }
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

void ungets(char s[])
{
    int i = strlen(s);
    while(i > 0) {
        ungetch(s[--i]);
    }
}
