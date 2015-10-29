#include <stdio.h>

typedef struct {
    int numinator;
    int denominator;
    double value;
} ratio_s;

ratio_s new_ratio(int num, int den) {
    return (ratio_s){ .numinator = num, .denominator = den, .value = num/(double)den};
}

void print_ratio(const ratio_s *r) {
    printf("numinator: %i, denominator: %i, value: %g\n", r->numinator, r->denominator, r->value);
}

ratio_s ratio_add(ratio_s left, ratio_s right) {
//    return new_ratio(left.numinator + right.numinator,
//                     right.denominator + right.denominator);
    return (ratio_s) {
        .numinator = left.numinator * right.denominator + right.numinator * left.denominator,
        .denominator = left.denominator * right.denominator,
        .value = left.value + right.value
    };
}

int main()
{
    ratio_s ra = new_ratio(1, 2);
    ratio_s rb = new_ratio(1, 3);
    ratio_s rc = ratio_add(ra, rb);


    print_ratio(&ra);
    print_ratio(&rb);
    print_ratio(&rc);

    return 0;
}
