#include <stdio.h>

int main(void)
{
    int tabs, blanks, newlines;
    char c;

    tabs = 0;
    blanks = 0;
    newlines = 0;

    printf("Press any character and press Enter, then do a couple of times.\n");

    int loop = 1;
    while(loop) {
        c = getchar();
        switch (c) {
            case ' ':
                blanks += 1;
                break;
            case '\t':
                tabs += 1;
                break;
            case '\n':
                newlines += 1;
                break;
            case EOF:
                loop = 0;
                break;
        }
    }

    printf("Blanks: %d, Tabs: %d, Newlines: %d\n\n", blanks, tabs, newlines);

    return 0;
}
