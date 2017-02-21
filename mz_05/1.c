#include <stdio.h>
#include "1.h"

extern unsigned extract1(unsigned value, int bit, int length);
int main() {
    printf("%u\n",extract1(1, 0, 1));

    return 0;
}
