#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int64_t val;
    char* endptr = 0;
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        val = strtol(argv[i], &endptr, 10);
        if (*argv[i] && !errno && !*endptr && val == (int32_t) val) {
            if (val == (int8_t) val) {
                printf("1\n");
            } else {
                if (val == (int16_t) val) {
                    printf("2\n");
                } else {
                        printf("4\n");
                }
            }
        } else printf("-1\n");
    }
}
