#include <stdio.h>

int
main()
{
    long long cur;
    long long diff = 0;
    long long min;
    scanf("%lld", &min);
    while(scanf("%lld", &cur) != EOF) {
        if (diff < cur - min) {
            diff = cur - min;
        }
        if (cur < min) {
            min = cur;
        }
    }
    printf("%lld\n", diff);
    return 0;
}
