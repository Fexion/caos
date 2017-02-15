#include <stdio.h>
#include <inttypes.h>

int main() {
    uint32_t a = 0, b = 0;
    int32_t c;
    scanf ("%d", &c);
    while (c != -1) {
        a |= (1UL << (c));
        scanf("%d", &c);
    }
    scanf("%d", &c);
    while (c != EOF) {
        while (c != -1) {
            b |= (1UL << (c));
            scanf("%d", &c);
        }
        scanf("%d", &c);
        a ^=b;
        b = 0;
    }
    printf ("%x\n", a);

    return 0;
}
