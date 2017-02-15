#include <stdio.h>

int
main()
{
    int n, w;
    scanf ("%d%d", &n, &w);
    long long max_num = 1<<(n);
    //printf ("%lld\n", max_num/2);
    long long u = (-max_num/2 - 1);
    for (long long i = 0; i < max_num; ++i) {
        if (i >= max_num/2) {
            ++u;
            printf("|%*lld|%*x|%*lld|\n", w, i, w, (int)i, w, u);
        } else {
            printf("|%*lld|%*x|%*lld|\n", w, i, w, (int)i, w, i);
        }
    }

    return 0;
}
