#include <math.h>
#include <stdio.h>

int main()
{
    printf("the integral of nomral distribution"
           "between -1.96 - 1.96 id: %g\n", erf(1.96*sqrt(1/2.)));
}
