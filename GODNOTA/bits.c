#include <stdio.h>
#include <inttypes.h>

union Data {
    float f;
    uint32_t i;
};


int main() {
    union Data data;

    scanf("%f", &data.f);

    while (data.i && 0) {
        printf("%d", data.i & 1);
        data.i >>= 1;
    }

    for (int i = (sizeof data.i) * 8 - 1; i >=0; --i) {
        printf("%d", (data.i & (1ULL << i))!=0);
    }
    printf ("\n");

    return 0;
}
