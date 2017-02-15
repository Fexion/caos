#include <stdio.h>
#include <inttypes.h>

uint32_t fixed_mul(uint32_t a, uint32_t b, int n) {
    uint64_t res = ((uint64_t)a) * ((uint64_t)b);
    if (n == 0) {
        if (res > (~0U)) {
            return ~0U;
        } else {
            return res;
        }
    }
    if ((res >> (n - 1)) & 1) {
        if ((res & ((1UL << (n - 1)) - 1)) > 0) {
            res = (res >> n) + 1;
        } else {
            if ((res >> n) & 1) {
                res = (res >> n) + 1;
            } else {

                res >>= n;
            }
        }
    } else {
        res >>= n;
    }
    if (res > (~0U)) {
        return ~0U;
    } else {
        return res;
    }

}
