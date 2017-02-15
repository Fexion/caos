#include <stdio.h>
#include <inttypes.h>

union Data
{
    float f;
    uint32_t i;
};


int main() {
    union Data data;

    while (scanf("%f", &data.f) != EOF) {
        int i = (sizeof data.i) * 8 - 1;
        uint32_t povv = 0, mant = 0;
        printf("%d ", (data.i & (1ULL << i))!=0);
        --i;
        for (int j = 0; j < 8; ++j, --i) {
            povv *=2;
            povv +=(data.i & (1ULL << i))!=0;
        }
        printf ("%u ", povv);
        for (int j = 0; j < 23; ++j, --i) {
            mant *=2;
            mant +=(data.i & (1ULL << i))!=0;
        }
        printf ("%x\n", mant);
    }
    return 0;
}
