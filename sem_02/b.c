#include <stdio.h>

int
main()
{
    int n;
    long long a, b, d, d1;
    scanf ("%lld%lld%d", &a, &b, &n);
    d = a * a;

    printf("%*s ", n, "");
    for (long long i = a; i < b; ++i) {
        if (i != b - 1) {
            printf("%*lld ", n, i);
        } else {
            printf("%*lld\n", n, i);
        }
    }



    for (long long i = a; i < b; ++i) {
        printf("%*lld ", n, i);
        d1 = d;
        for (long long j = a; j < b; ++j) {
            if (j != b - 1) {
                printf("%*lld ", n, d1);
            } else {
                printf("%*lld\n", n, d1);
            }
            d1 += i;
        }
        d += a;
    }
    return 0;
}
