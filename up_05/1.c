#include <stdio.h>

unsigned extract(unsigned value, int bit, int length);
int main() {
    printf("%u\n",extract(1022, 1, 2));

    return 0;
}
