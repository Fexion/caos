#include <inttypes.h>
#include <stdio.h>

int main() {
    uint32_t hex;
    int f;
    char count;
    uint64_t ans = 0;
    while ((f = (scanf("%x", &hex) + 1))) {
        for (int i = 0; i < 4 && f; ++i) {
            count = 4;
            ans = 0;
            while (count && (f = (scanf("%x", &hex) + 1))) {
                ans <<= 8;
                ans += hex;
                --count;
            }
            if (!count && f) {
                printf ("%lu\n", ans);
            }

        }
    }
    return 0;
}
