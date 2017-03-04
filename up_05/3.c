
#include <stdint.h>
#include <stdio.h>

extern void myexp(double x, double *r);

int main() {
    double a = 4;
    double res = 0;

    myexp(a, &res);
    printf("%.20lf\n", res);
    return 0;
}
