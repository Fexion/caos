#include <stdio.h>

int
main()
{
    long long a, b = 0, c;
    scanf("%lld", &a);
    while (scanf("%lld", &c) != EOF) {
        if (c > b) {
            b = c;
        }
        if (b > a) {
            c = a;
            a = b;
            b = c;
        }
    }
    printf("%lld\n", a * b);

    return 0;
}
