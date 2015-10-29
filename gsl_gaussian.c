#include <stdio.h>
#include <gsl/gsl_cdf.h>

int main()
{
    double bottom_tail = gsl_cdf_gaussian_P(-1.96, 1);
    printf("Area: %g\n", 1 - 2 * bottom_tail);
    return 0;
}

