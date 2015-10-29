#include <stdio.h>

void error_log(FILE* fh, char *msg, int code)
{
    fprintf(fh, "error description: %s, error code: %i\n", msg, code);
}

int main()
{
    FILE *fh = fopen("error_file", "w");
    error_log(fh, "nomen omen", 34);

    return 0;
}
