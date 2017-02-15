#include <stdio.h>
#include <ctype.h>

int
main()
{
    int c;
    long long count = 0;
    while ((c = getchar_unlocked()) != EOF) {
        if (isdigit(c)) {
            count += (c - '0');
        }
    }
    printf("%lld\n", count);
    return 0;
}
