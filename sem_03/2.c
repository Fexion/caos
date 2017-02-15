#include <inttypes.h>
#include <stdio.h>
int32_t satsum(int32_t v1, int32_t v2) {
    int32_t max_32 = (~(uint32_t)0)>>1;
    int32_t min_32 = (~(uint32_t)0) ^ max_32;
    int32_t sum;
    if (!__builtin_add_overflow(v1, v2, &sum)) {
        return sum;
    } else {
        if (v1 > 0 || v2 > 0) {
            return max_32;
        } else {
            return min_32;
        }
    }
}
