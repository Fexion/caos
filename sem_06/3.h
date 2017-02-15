#include <stdio.h>
#include <inttypes.h>


uint32_t fixed_mul(uint32_t a, uint32_t b, int n) {
    uint64_t res = ((uint64_t)a) * ((uint64_t)b);
    if (n == 0) {
        if (res > (~0U)) {
            return ~0U;
        }
        return res;
    }
    if (((((res >> 32) >> n)) & (~0LU)) > 0) {
        return ~0U;
    }
    if ((res & ((1UL << n) - 1)) < (1UL << (n-1))) {
        return res >> n;
    } else if ((res & ((1UL << n) - 1)) == (1UL << (n-1))) {
        if ((res & (1UL << n)) == 0) {
            return res >> n;
        } else {
            res = (res >> n) + 1;
            if (((res >> 32) & (~0UL)) > 0) {
                return ~0U;
            } else {
                return res;
            }
        }
    } else {
        res = (res >> n) + 1;
        if (((res >> 32) & (~0UL)) > 0) {
            return ~0U;
        } else {
            return res;
        }
    }
}
