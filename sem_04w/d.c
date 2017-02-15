#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

int main() {
    int32_t  cur;
    int64_t  ans = 0;
    char f = 0;
    char over = 0;
    while((cur = getchar_unlocked()) != EOF) {
        if (isspace(cur)) {
            if (f) {
                if (over) {
                    printf ("%d\n", (int32_t)((~(0U) >> 1) + 1));
                    over = 0;
                } else {
                    printf ("%lld\n", ans);
                }

                f = 0;
                ans = 0;
            }
        } else if (!over) {
            f = 1;
            if (cur == 'a') {
                ans = ans * 3 - 1;
            } else if (cur == '0') {
                ans *= 3;
            } else {
                ans = ans * 3 + 1;
            }
            if (ans > (~(0U) >> 1) || ans < (int32_t)((~(0U) >> 1) + 1)) {
                over = 1;
            }
        }
    }
    if (f) {
        if (over) {
            printf ("%d\n", (int32_t)((~(0U) >> 1) + 1));
        } else {
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
