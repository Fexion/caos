#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[]) {
    char* endptr = 0;

    for (int i = 1; i < argc; ++i) {
        errno = 0;
        int64_t num = strtol(argv[i], &endptr, 10);
        if (num & (1ULL << 63)) {
            num = ~num;
        }
        if (!*argv[i] || *endptr || errno) {
            printf("-1\n");
        } else if (!(num & ~((1ULL << 7) - 1))) {
            printf ("1\n");
        } else if (!(num & ~((1ULL << 15) - 1))) {
            printf("2\n");
        } else if (!(num & ~((1ULL << 31) - 1))) {
            printf ("4\n");
        } else {
            printf("-1\n");
        }

    }

    return 0;
}
