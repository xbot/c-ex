/*
 * Exercise 5-19. Modify undcl so that it does not add redundant parentheses to declarations.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../lib/getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

int hastoken = 0;

int main() /* convert declaration to words */
{
    int type;
    char temp[MAXTOKEN];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                int	count = 0;
                do {
                    count++;
                    gettoken();
                } while (tokentype == '*');
                temp[0] = '\0';
                if (tokentype != NAME) 
                    strcat(temp, "(");
                while (count--)
                    strcat(temp, "*");
                strcat(temp, out);
                if (tokentype != NAME) 
                    strcat(temp, ")");
                strcpy(out, temp);
                continue;
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        /* ( dcl ) */
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            hastoken = 1;
        }
    } else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else {
        printf("error: expected name or (dcl)\n");
        hastoken = 1;
    }
    while ((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (hastoken) {
        hastoken = 0;
        return tokentype;
    }

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}
