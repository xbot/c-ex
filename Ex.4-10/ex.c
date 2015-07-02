/*
 * Exercise 4-10. An alternate organization uses get_line to read an entire input
 * line; this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
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
#define MAX_LINE_LEN 1000

int pos = 0;
double stack[MAXVAL];
int idx = 0;
char line[MAX_LINE_LEN];

int getop(char []);
void push(double);
double pop(void);
int get_line(char line[], int limit);

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

    if (line[idx] == '\0') {
        if (get_line(line, MAX_LINE_LEN) == 0) {
            return EOF;
        } else {
            idx = 0;
        }
    }

    while((s[0] = c = line[idx++]) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (islower(c)) {
        while(islower(s[++i] = c = line[idx++]));
        s[i] = '\0';
        if (c != EOF) {
            idx--;
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
        while((isdigit(s[++i] = c = line[idx++])));
    }
    if (c == '.') {
        while((isdigit(s[++i] = c = line[idx++])));
    }
    s[i] = '\0';
    idx--;

    return NUMBER;
}

int get_line(char line[], int limit)
{
    int i = 0, c;

    while((c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
}
