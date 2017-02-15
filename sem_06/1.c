#include <stdio.h>
#include <inttypes.h>

int main() {
    uint32_t a;
    float b;
    while (scanf("%u", &a) != EOF) {
            b = (float)a;
            if (a == (uint32_t)b) {
                printf ("1\n");
            } else {
                printf ("0\n");
            }
    }
    return 0;
}
