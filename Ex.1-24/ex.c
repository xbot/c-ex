/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This pro-
 * gram is hard if you do it in full generality.)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

#define MAX_LINE_LEN 1000

jmp_buf jb;
int errno;
#define try if((errno = setjmp(jb)) == 0)
#define catch else
#define throw(v) longjmp(jb, v)

#define ERR_COMMENT_INCOMPLETE  1
#define ERR_QUOTE_INCOMPLETE    2
#define ERR_PARENTHESE_UNPAIRED 3
#define ERR_BRACKET_UNPAIRED    4
#define ERR_BRACE_UNPAIRED      5

int get_line(char line[], int maxLen);
char* remove_comments(char line[]);
char* remove_quoted_string(char line[]);

int main(void)
{
    char line[MAX_LINE_LEN];
    int len, i;
    char *newLine1, *newLine2;
    int stackPar = 0, stackBracket = 0, stackBrace = 0;

    while((len = get_line(line, MAX_LINE_LEN)) > 0) {
        try {
            // remove comments
            newLine1 = remove_comments(line);
            // remove quoted strings
            newLine2 = remove_quoted_string(newLine1);
            free(newLine1);
            // check parentheses, brackets, braces
            for (i = 0; i < strlen(newLine2); ++i) {
                switch (newLine2[i]) {
                    case '(':
                        stackPar++;
                        break;
                    case ')':
                        stackPar--;
                        break;
                    case '[':
                        stackBracket++;
                        break;
                    case ']':
                        stackBracket--;
                        break;
                    case '{':
                        stackBrace++;
                        break;
                    case '}':
                        stackBrace--;
                        break;
                }

                if (stackPar < 0) {
                    free(newLine2);
                    throw(ERR_PARENTHESE_UNPAIRED);
                }
                if (stackBracket < 0) {
                    free(newLine2);
                    throw(ERR_BRACKET_UNPAIRED);
                }
                if (stackBrace < 0) {
                    free(newLine2);
                    throw(ERR_BRACE_UNPAIRED);
                }
            }

            free(newLine2);

            if (stackPar != 0) {
                throw(ERR_PARENTHESE_UNPAIRED);
            }
            if (stackBracket != 0) {
                throw(ERR_BRACKET_UNPAIRED);
            }
            if (stackBrace != 0) {
                throw(ERR_BRACE_UNPAIRED);
            }
        } catch {
            switch (errno) {
                case ERR_COMMENT_INCOMPLETE:
                    puts("Incomplete comment found.\n");
                    break;
                case ERR_QUOTE_INCOMPLETE:
                    puts("Incomplete quote found.\n");
                    break;
                case ERR_PARENTHESE_UNPAIRED:
                    puts("Unpaired parenthese found.\n");
                    break;
                case ERR_BRACKET_UNPAIRED:
                    puts("Unpaired bracket found.\n");
                    break;
                case ERR_BRACE_UNPAIRED:
                    puts("Unpaired brace found.\n");
                    break;
                default:
                    printf("Unknow errno: %d.\n\n", errno);
            }
        }

        for (i = 0; i < MAX_LINE_LEN; ++i) {
            line[i] = 0;
        }
    }

    return errno;
}

int get_line(char line[], int maxLen)
{
    int i = 0;
    char c;

    while(i < maxLen && (c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}

char* remove_comments(char line[])
{
    char *newLine;
    int i, j=0;
    int len = strlen(line);
    int inComment = 0, inQuote = 0;

    newLine = malloc(len * sizeof(char));

    for (i = 0; i < len; ++i) {
        if (!inComment) {
            if (inQuote || line[i] == '"') {
                newLine[j++] = line[i];
            }
            if (line[i] == '"') {
                inQuote = !inQuote;
                continue;
            }
        }

        if (!inQuote) {
            if (inComment) {
                if (line[i] == '*' && line[i+1] == '/') {
                    inComment = 0;
                    i++;
                }
            } else {
                if (line[i] == '/' && line[i+1] == '*') {
                    inComment = 1;
                    i++;
                } else {
                    newLine[j++] = line[i];
                }
            }
        }
    }

    if (inComment) {
        free(newLine);
        throw(ERR_COMMENT_INCOMPLETE);
    }

    return newLine;
}

char* remove_quoted_string(char line[])
{
    char *newLine;
    int i, j=0;
    int len = strlen(line);
    int inQuote = 0;

    newLine = malloc(len * sizeof(char));

    for (i = 0; i < len; ++i) {
        if (!inQuote && line[i] != '"') {
            newLine[j++] = line[i];
        }
        if (line[i] == '"') {
            inQuote = !inQuote;
        }
    }

    if (inQuote) {
        free(newLine);
        throw(ERR_QUOTE_INCOMPLETE);
    }

    return newLine;
}
