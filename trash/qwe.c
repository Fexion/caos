#include <stdio.h>
#include <inttypes.h>
int main() {
    printf ("%d", ((~(int32_t)0)>>31));

    return 0;
}
