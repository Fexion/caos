#include <inttypes.h>

uint64_t addmod(uint64_t a, uint64_t b, uint64_t c) {
    a %= c;
    b %= c;
    uint64_t sum;
    if (!__builtin_add_overflow(a, b, &sum)) {
        return sum % c;
    } else {
        return a - (c - b);
    }
}
