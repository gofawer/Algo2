#include <stdio.h>

void error_print(FILE *ff, int error_code, char *msg)
{
    fprintf(ff, "Error %i occured: %s\n", error_code, msg);
}

int main()
{
    FILE *error_file = fopen("example_error_file", "w");
    error_print(error_file, 34, "out of karma");

    return 0;
}

