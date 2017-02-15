#include <stdio.h>
#include <inttypes.h>

int main() {
    uint32_t inp;
    while (scanf("%u", &inp) != EOF) {
        uint32_t count = 31;
        uint32_t last_1 = 31;
        char f = 1;
        for (int i = 0; i < 32; ++i) {
            if (f) {
                if (inp & (1ULL << i)) {
                    f = 0;
                    count = i;
                    last_1 = i + 1;
                }
            } else if (inp & (1ULL << i)) {
                last_1 = i + 1;
            }
        }
        if (last_1 - count > 24) {
            printf ("0\n");
        } else {
            printf ("1\n");
        }


    }
    return 0;
}
