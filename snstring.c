#include <stdio.h>

int intlist[10];

int main()
{
    int len = 20;
    char string[len];
    intlist[7] = 7;

    snprintf(string, len, "nomen omen %i", intlist[7]);
    printf("msg: %s\n", string);

    return 0;
}
