#include <stdio.h>
#include <inttypes.h>

int
main()
{
    int32_t cur;
    uint32_t diff = 0;
    int32_t last;
    int32_t min;
    uint32_t cur_diff;

    scanf("%" SCNd32, &min);
    last = min;
    while(scanf("%" SCNd32, &cur) != EOF) {
        if (cur >= last) {
            if (cur >= 0 && min < 0) {
                cur_diff = (uint32_t)cur - min;
            } else {
                cur_diff = cur - min;
            }
            if (diff < cur_diff) {
                diff = cur_diff;
            }
        } else {
            min = cur;
        }
        last = cur;
    }
    printf("%u\n", diff);
    return 0;
}
