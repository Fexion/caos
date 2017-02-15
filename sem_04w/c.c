#include "c.h"
#include <stdio.h>

int main() {
    uint64_t a, b, c;
    scanf("%lu%lu%lu", &a, &b, &c);

    printf ("%lu\n", addmod(a, b, c));
    return 0;
}
